// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ArmContactState.proto

package messages;

public final class _File_ArmContactState {
  private _File_ArmContactState() {}
  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistry registry) {
  }
  static com.google.protobuf.Descriptors.Descriptor
    internal_static_messages_ArmContactState_descriptor;
  static
    com.google.protobuf.GeneratedMessage.FieldAccessorTable
      internal_static_messages_ArmContactState_fieldAccessorTable;

  public static com.google.protobuf.Descriptors.FileDescriptor
      getDescriptor() {
    return descriptor;
  }
  private static com.google.protobuf.Descriptors.FileDescriptor
      descriptor;
  static {
    java.lang.String[] descriptorData = {
      "\n\025ArmContactState.proto\022\010messages\"\237\002\n\017Ar" +
      "mContactState\022E\n\024right_push_direction\030\001 " +
      "\001(\0162\'.messages.ArmContactState.PushDirec" +
      "tion\022D\n\023left_push_direction\030\002 \001(\0162\'.mess" +
      "ages.ArmContactState.PushDirection\"\177\n\rPu" +
      "shDirection\022\010\n\004NONE\020\000\022\t\n\005NORTH\020\001\022\r\n\tNORT" +
      "HEAST\020\002\022\010\n\004EAST\020\003\022\r\n\tSOUTHEAST\020\004\022\t\n\005SOUT" +
      "H\020\005\022\r\n\tSOUTHWEST\020\006\022\010\n\004WEST\020\007\022\r\n\tNORTHWES" +
      "T\020\010B\031B\025_File_ArmContactStateP\001"
    };
    com.google.protobuf.Descriptors.FileDescriptor.InternalDescriptorAssigner assigner =
      new com.google.protobuf.Descriptors.FileDescriptor.InternalDescriptorAssigner() {
        public com.google.protobuf.ExtensionRegistry assignDescriptors(
            com.google.protobuf.Descriptors.FileDescriptor root) {
          descriptor = root;
          internal_static_messages_ArmContactState_descriptor =
            getDescriptor().getMessageTypes().get(0);
          internal_static_messages_ArmContactState_fieldAccessorTable = new
            com.google.protobuf.GeneratedMessage.FieldAccessorTable(
              internal_static_messages_ArmContactState_descriptor,
              new java.lang.String[] { "RightPushDirection", "LeftPushDirection", });
          return null;
        }
      };
    com.google.protobuf.Descriptors.FileDescriptor
      .internalBuildGeneratedFileFrom(descriptorData,
        new com.google.protobuf.Descriptors.FileDescriptor[] {
        }, assigner);
  }

  // @@protoc_insertion_point(outer_class_scope)
}
