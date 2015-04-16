package nbtool.data;

import java.io.ByteArrayInputStream;
import java.io.DataInputStream;
import java.io.IOException;

import nbtool.util.U;

public class RobotStats {
	public RobotStats(Log log) throws IOException {
		
	}
	
	public int NUM_LOG_BUFFERS;
	public int cores;
	
	public int[] ratio;
	public int[] size;
	
	public BufStat[] fio_stat;
	public BufStat[] cio_stat;
	public BufStat[] tot_stat;
	
	public BufManage[] manage;
	
	public long con_uptime;
	public long cnc_uptime;
	
	public long fio_uptime;
	public long sio_uptime;
	
	public long log_uptime;
	
	public Flags flags;
	
	private final String manage_header = String.format("\t%10s%10s%10s\n", "servnr", "filenr", "nextw");
	private class BufManage {
		public int servnr;
		public int filenr;
		public int nextw;
		
		public String toString() {
			return String.format("\t%10d%10d%10d\n", servnr, filenr, nextw);
		}
	}
	
	private final String stat_header = String.format("\t%20s%20s%20s%20s%20s%20s%20s\n",
			"lgiven", "bgiven", "lwrit", "bwrit", "llost", "blost", "lfreed");
	private class BufStat {
		public BufStat(DataInputStream is) throws IOException {
			b_given = is.readLong();
			b_lost = is.readLong();
			b_writ = is.readLong();

			l_given = is.readInt();
			
			l_freed = is.readInt();
			l_lost = is.readInt();

			l_writ = is.readInt();
		}
		
		public int l_given;
		public int l_freed;
		public int l_lost;
		public int l_writ;
		
		public long b_given;
		public long b_lost;
		public long b_writ;
		
		public String toString() {
			return String.format("\t%20d%20d%20d%20d%20d%20d%20d\n",
					l_given, b_given, l_writ, b_writ, l_lost, b_lost, l_freed);
		}
	}

	public class Flags {
        
        public String toString() {
        	String[] parts = new String[flag_names.length];
        	
        	for (int i = 0; i < parts.length; ++i) {
        		parts[i] = String.format("%-20s %B\n", flag_names[i], bFlags[i]);
        	}
        	
        	String start = "\n\tFlags:\n";
        	int len = start.length();
    		for (String s : parts) len += s.length();
    		StringBuilder buf = new StringBuilder(len);
    		
    		buf.append(start);
    		for (String s : parts) buf.append(s);
    		return buf.toString();
        }
        
        public boolean[] bFlags;
        
        public Flags(DataInputStream dis) throws IOException {
        	bFlags = new boolean[flag_names.length];
        	for (int i = 0; i < bFlags.length; ++i) {
        		bFlags[i] = (dis.readByte() != 0);
        	}
        }
	}
	
	public static final String[] flag_names = {"serv_connected",
		"cnc_connected", "fileio", "servio", "STATS", "SENSORS",
		"GUARDIAN", "COMM", "LOCATION", "ODOMETRY",
		"OBSERVATIONS", "LOCALIZATION", "BALLTRACK",
		"IMAGES", "VISION"};
	
	public String toString() {
		String[] parts = new String[7 + (5 * NUM_LOG_BUFFERS)];
		int pindex = 0;
		
		parts[pindex++] = String.format("nbuffers=%d num_cores=%d\n", NUM_LOG_BUFFERS, cores);
		parts[pindex++] = String.format("\n\t%10s%10s\n", "ratio", "size");
		for (int i = 0; i < NUM_LOG_BUFFERS; ++i) {
			parts[pindex++] = i + String.format("\t%10d%10d\n", ratio[i], size[i]);
		}
		
		parts[pindex++] = "\n" + stat_header;
		for (int i = 0; i < NUM_LOG_BUFFERS; ++i) {
			parts[pindex++] = "fio-" + i + fio_stat[i].toString();
		}
		
		for (int i = 0; i < NUM_LOG_BUFFERS; ++i) {
			parts[pindex++] = "cio-" + i + cio_stat[i].toString();
		}
		
		for (int i = 0; i < NUM_LOG_BUFFERS; ++i) {
			parts[pindex++] = "tot-" + i + tot_stat[i].toString();
		}
		
		parts[pindex++] = "\n" + manage_header;
		for (int i = 0; i < NUM_LOG_BUFFERS; ++i) {
			parts[pindex++] = i + manage[i].toString();
		}
		
		parts[pindex++] = "\n\tTiming:\n";
		parts[pindex++] = String.format("con-up= %d\ncnc-up= %d\nfio-up= %d\nsio-up= %d\nlog-up= %d\n",
				con_uptime, cnc_uptime, fio_uptime, sio_uptime, log_uptime);
		
		parts[pindex++] = flags.toString();
		
		int len = 0;
		for (String s : parts) len += s.length();
		StringBuilder buf = new StringBuilder(len);
		
		for (String s : parts) buf.append(s);
		return buf.toString();
	}
}
