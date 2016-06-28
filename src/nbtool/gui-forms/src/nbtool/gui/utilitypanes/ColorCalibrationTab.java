/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package nbtool.gui.utilitypanes;

/**
 *
 * @author calini
 */
public class ColorCalibrationTab extends javax.swing.JPanel {

    /**
     * Creates new form FrontEndView
     */
    public ColorCalibrationTab() {
        initComponents();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        internal = new javax.swing.JPanel();
        jPanel3 = new javax.swing.JPanel();
        jPanelY2 = new javax.swing.JPanel();
        Y0Text2 = new javax.swing.JLabel();
        Y0UText2 = new javax.swing.JLabel();
        Y0VText2 = new javax.swing.JLabel();
        Y0USlider = new javax.swing.JSlider();
        Y0VSlider = new javax.swing.JSlider();
        Y0USpinner = new javax.swing.JSpinner();
        Y0VSpinner = new javax.swing.JSpinner();
        jLabel13 = new javax.swing.JLabel();
        jLabel14 = new javax.swing.JLabel();
        jLabel15 = new javax.swing.JLabel();
        jLabel16 = new javax.swing.JLabel();
        jLabel17 = new javax.swing.JLabel();
        jLabel18 = new javax.swing.JLabel();
        jPanelY257 = new javax.swing.JPanel();
        Y255Text2 = new javax.swing.JLabel();
        Y255UText2 = new javax.swing.JLabel();
        Y255VText2 = new javax.swing.JLabel();
        Y255USlider = new javax.swing.JSlider();
        Y255VSlider = new javax.swing.JSlider();
        Y255USpinner = new javax.swing.JSpinner();
        Y255VSpinner = new javax.swing.JSpinner();
        Y255UMinText2 = new javax.swing.JLabel();
        Y255UMaxText2 = new javax.swing.JLabel();
        Y255UMiddleText2 = new javax.swing.JLabel();
        Y255VMinText2 = new javax.swing.JLabel();
        Y255VMiddleText2 = new javax.swing.JLabel();
        Y255VMaxText2 = new javax.swing.JLabel();
        jPanelFuzzy2 = new javax.swing.JPanel();
        FuzzyText2 = new javax.swing.JLabel();
        FuzzyUText2 = new javax.swing.JLabel();
        FuzzyVText2 = new javax.swing.JLabel();
        FuzzyUSlider = new javax.swing.JSlider();
        FuzzyVSlider = new javax.swing.JSlider();
        FuzzyUSpinner = new javax.swing.JSpinner();
        FuzzyVSpinner = new javax.swing.JSpinner();
        FuzzyUMinText2 = new javax.swing.JLabel();
        FuzzyUMaxText2 = new javax.swing.JLabel();
        FuzzyUMiddleText2 = new javax.swing.JLabel();
        FuzzyVMinText2 = new javax.swing.JLabel();
        FuzzyVMiddleText2 = new javax.swing.JLabel();
        FuzzyVMaxText2 = new javax.swing.JLabel();
        UndoButton = new javax.swing.JButton();
        SaveButton = new javax.swing.JButton();
        SendButton = new javax.swing.JButton();
        tabTitle = new javax.swing.JLabel();
        globalCheckBox = new javax.swing.JCheckBox();
        takeCheckBox = new javax.swing.JCheckBox();
        imageSplitPane = new javax.swing.JSplitPane();

        internal.setBackground(new java.awt.Color(242, 242, 242));
        internal.setBorder(javax.swing.BorderFactory.createTitledBorder(new javax.swing.border.LineBorder(new java.awt.Color(0, 0, 0), 2, true), "camera color calibration", javax.swing.border.TitledBorder.DEFAULT_JUSTIFICATION, javax.swing.border.TitledBorder.DEFAULT_POSITION, new java.awt.Font("PT Serif", 1, 14))); // NOI18N

        jPanelY2.setBackground(new java.awt.Color(232, 238, 238));

        Y0Text2.setFont(new java.awt.Font("Lucida Grande", 1, 13)); // NOI18N
        Y0Text2.setText("Y = 0");

        Y0UText2.setText("U");

        Y0VText2.setText("V");

        Y0USpinner.setModel(new javax.swing.SpinnerNumberModel(0, 0, 255, 1));

        Y0VSpinner.setModel(new javax.swing.SpinnerNumberModel(0, 0, 255, 1));

        jLabel13.setText("0");

        jLabel14.setText("255");

        jLabel15.setText("127");

        jLabel16.setText("0");

        jLabel17.setText("127");

        jLabel18.setText("255");

        javax.swing.GroupLayout jPanelY2Layout = new javax.swing.GroupLayout(jPanelY2);
        jPanelY2.setLayout(jPanelY2Layout);
        jPanelY2Layout.setHorizontalGroup(
            jPanelY2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanelY2Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanelY2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanelY2Layout.createSequentialGroup()
                        .addComponent(Y0UText2)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 12, Short.MAX_VALUE)
                        .addGroup(jPanelY2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(jPanelY2Layout.createSequentialGroup()
                                .addComponent(Y0USlider, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 11, Short.MAX_VALUE))
                            .addGroup(jPanelY2Layout.createSequentialGroup()
                                .addComponent(jLabel13)
                                .addGap(78, 78, 78)
                                .addComponent(jLabel15)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addComponent(jLabel14)
                                .addGap(10, 10, 10))))
                    .addGroup(jPanelY2Layout.createSequentialGroup()
                        .addGroup(jPanelY2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addGroup(jPanelY2Layout.createSequentialGroup()
                                .addComponent(Y0Text2)
                                .addGap(174, 174, 174))
                            .addGroup(jPanelY2Layout.createSequentialGroup()
                                .addComponent(Y0VText2)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addGroup(jPanelY2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                    .addGroup(jPanelY2Layout.createSequentialGroup()
                                        .addComponent(jLabel16)
                                        .addGap(78, 78, 78)
                                        .addComponent(jLabel17)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                        .addComponent(jLabel18))
                                    .addComponent(Y0VSlider, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))))
                        .addGap(6, 6, 6)))
                .addGroup(jPanelY2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(Y0VSpinner, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(Y0USpinner, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(34, Short.MAX_VALUE))
        );
        jPanelY2Layout.setVerticalGroup(
            jPanelY2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanelY2Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(Y0Text2)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jPanelY2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanelY2Layout.createSequentialGroup()
                        .addGroup(jPanelY2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                            .addComponent(Y0UText2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(Y0USlider, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE))
                        .addGap(2, 2, 2)
                        .addGroup(jPanelY2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addGroup(jPanelY2Layout.createSequentialGroup()
                                .addGroup(jPanelY2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                    .addComponent(jLabel13)
                                    .addComponent(jLabel14)
                                    .addComponent(jLabel15))
                                .addGap(10, 10, 10)
                                .addComponent(Y0VSlider, javax.swing.GroupLayout.PREFERRED_SIZE, 20, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addComponent(Y0VText2)))
                    .addGroup(jPanelY2Layout.createSequentialGroup()
                        .addComponent(Y0USpinner, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(Y0VSpinner, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanelY2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel16)
                    .addComponent(jLabel17)
                    .addComponent(jLabel18))
                .addContainerGap(45, Short.MAX_VALUE))
        );

        jPanelY257.setBackground(new java.awt.Color(232, 238, 238));

        Y255Text2.setFont(new java.awt.Font("Lucida Grande", 1, 13)); // NOI18N
        Y255Text2.setText("Y = 255");

        Y255UText2.setText("U");

        Y255VText2.setText("V");

        Y255USpinner.setModel(new javax.swing.SpinnerNumberModel(0, 0, 255, 1));

        Y255VSpinner.setModel(new javax.swing.SpinnerNumberModel(0, 0, 255, 1));

        Y255UMinText2.setText("0");

        Y255UMaxText2.setText("255");

        Y255UMiddleText2.setText("127");

        Y255VMinText2.setText("0");

        Y255VMiddleText2.setText("127");

        Y255VMaxText2.setText("255");

        javax.swing.GroupLayout jPanelY257Layout = new javax.swing.GroupLayout(jPanelY257);
        jPanelY257.setLayout(jPanelY257Layout);
        jPanelY257Layout.setHorizontalGroup(
            jPanelY257Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanelY257Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanelY257Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanelY257Layout.createSequentialGroup()
                        .addGroup(jPanelY257Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(Y255UText2)
                            .addComponent(Y255VText2))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addGroup(jPanelY257Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(jPanelY257Layout.createSequentialGroup()
                                .addGroup(jPanelY257Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                    .addGroup(jPanelY257Layout.createSequentialGroup()
                                        .addComponent(Y255UMinText2)
                                        .addGap(78, 78, 78)
                                        .addComponent(Y255UMiddleText2)
                                        .addGap(56, 56, 56)
                                        .addComponent(Y255UMaxText2))
                                    .addComponent(Y255USlider, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addComponent(Y255USpinner, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(53, 53, 53))
                            .addGroup(jPanelY257Layout.createSequentialGroup()
                                .addGroup(jPanelY257Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                    .addGroup(jPanelY257Layout.createSequentialGroup()
                                        .addComponent(Y255VMinText2)
                                        .addGap(78, 78, 78)
                                        .addComponent(Y255VMiddleText2)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                        .addComponent(Y255VMaxText2))
                                    .addComponent(Y255VSlider, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(Y255VSpinner, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))))
                    .addGroup(jPanelY257Layout.createSequentialGroup()
                        .addComponent(Y255Text2)
                        .addGap(0, 0, Short.MAX_VALUE))))
        );
        jPanelY257Layout.setVerticalGroup(
            jPanelY257Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanelY257Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(Y255Text2)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jPanelY257Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanelY257Layout.createSequentialGroup()
                        .addComponent(Y255USpinner, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(16, 16, 16)
                        .addComponent(Y255VSpinner, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jPanelY257Layout.createSequentialGroup()
                        .addGroup(jPanelY257Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                            .addComponent(Y255UText2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(Y255USlider, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE))
                        .addGap(2, 2, 2)
                        .addGroup(jPanelY257Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(Y255UMinText2)
                            .addComponent(Y255UMaxText2)
                            .addComponent(Y255UMiddleText2))
                        .addGap(14, 14, 14)
                        .addGroup(jPanelY257Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(Y255VSlider, javax.swing.GroupLayout.PREFERRED_SIZE, 20, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(Y255VText2))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(jPanelY257Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(Y255VMinText2)
                            .addComponent(Y255VMaxText2)
                            .addComponent(Y255VMiddleText2))))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        jPanelFuzzy2.setBackground(new java.awt.Color(232, 238, 238));

        FuzzyText2.setFont(new java.awt.Font("Lucida Grande", 1, 13)); // NOI18N
        FuzzyText2.setText("Width of Fuzzy Threshold");

        FuzzyUText2.setText("U");

        FuzzyVText2.setText("V");

        FuzzyUSpinner.setModel(new javax.swing.SpinnerNumberModel(0, 0, 255, 1));

        FuzzyVSpinner.setModel(new javax.swing.SpinnerNumberModel(0, 0, 255, 1));

        FuzzyUMinText2.setText("0");

        FuzzyUMaxText2.setText("255");

        FuzzyUMiddleText2.setText("127");

        FuzzyVMinText2.setText("0");

        FuzzyVMiddleText2.setText("127");

        FuzzyVMaxText2.setText("255");

        javax.swing.GroupLayout jPanelFuzzy2Layout = new javax.swing.GroupLayout(jPanelFuzzy2);
        jPanelFuzzy2.setLayout(jPanelFuzzy2Layout);
        jPanelFuzzy2Layout.setHorizontalGroup(
            jPanelFuzzy2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanelFuzzy2Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanelFuzzy2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanelFuzzy2Layout.createSequentialGroup()
                        .addGroup(jPanelFuzzy2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(FuzzyUText2)
                            .addComponent(FuzzyVText2))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addGroup(jPanelFuzzy2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(jPanelFuzzy2Layout.createSequentialGroup()
                                .addGroup(jPanelFuzzy2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                    .addGroup(jPanelFuzzy2Layout.createSequentialGroup()
                                        .addComponent(FuzzyUMinText2)
                                        .addGap(78, 78, 78)
                                        .addComponent(FuzzyUMiddleText2)
                                        .addGap(56, 56, 56)
                                        .addComponent(FuzzyUMaxText2))
                                    .addComponent(FuzzyUSlider, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addComponent(FuzzyUSpinner, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(53, 53, 53))
                            .addGroup(jPanelFuzzy2Layout.createSequentialGroup()
                                .addGroup(jPanelFuzzy2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                    .addGroup(jPanelFuzzy2Layout.createSequentialGroup()
                                        .addComponent(FuzzyVMinText2)
                                        .addGap(78, 78, 78)
                                        .addComponent(FuzzyVMiddleText2)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                        .addComponent(FuzzyVMaxText2))
                                    .addComponent(FuzzyVSlider, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(FuzzyVSpinner, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))))
                    .addGroup(jPanelFuzzy2Layout.createSequentialGroup()
                        .addComponent(FuzzyText2)
                        .addGap(0, 0, Short.MAX_VALUE))))
        );
        jPanelFuzzy2Layout.setVerticalGroup(
            jPanelFuzzy2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanelFuzzy2Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(FuzzyText2)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jPanelFuzzy2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanelFuzzy2Layout.createSequentialGroup()
                        .addComponent(FuzzyUSpinner, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(16, 16, 16)
                        .addComponent(FuzzyVSpinner, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jPanelFuzzy2Layout.createSequentialGroup()
                        .addGroup(jPanelFuzzy2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                            .addComponent(FuzzyUText2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(FuzzyUSlider, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE))
                        .addGap(2, 2, 2)
                        .addGroup(jPanelFuzzy2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(FuzzyUMinText2)
                            .addComponent(FuzzyUMaxText2)
                            .addComponent(FuzzyUMiddleText2))
                        .addGap(14, 14, 14)
                        .addGroup(jPanelFuzzy2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(FuzzyVSlider, javax.swing.GroupLayout.PREFERRED_SIZE, 20, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(FuzzyVText2))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(jPanelFuzzy2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(FuzzyVMinText2)
                            .addComponent(FuzzyVMaxText2)
                            .addComponent(FuzzyVMiddleText2))))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        javax.swing.GroupLayout jPanel3Layout = new javax.swing.GroupLayout(jPanel3);
        jPanel3.setLayout(jPanel3Layout);
        jPanel3Layout.setHorizontalGroup(
            jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel3Layout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(jPanelY2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, Short.MAX_VALUE)
                .addComponent(jPanelY257, javax.swing.GroupLayout.PREFERRED_SIZE, 315, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, Short.MAX_VALUE)
                .addComponent(jPanelFuzzy2, javax.swing.GroupLayout.PREFERRED_SIZE, 315, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        jPanel3Layout.setVerticalGroup(
            jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel3Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jPanelFuzzy2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jPanelY257, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jPanelY2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap())
        );

        UndoButton.setText("Undo");
        UndoButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                UndoButtonActionPerformed(evt);
            }
        });

        SaveButton.setText("save to config");
        SaveButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                SaveButtonActionPerformed(evt);
            }
        });

        SendButton.setText("sent to robot");
        SendButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                SendButtonActionPerformed(evt);
            }
        });

        tabTitle.setFont(new java.awt.Font("Lucida Grande", 1, 18)); // NOI18N
        tabTitle.setText("jLabel1");

        globalCheckBox.setSelected(true);
        globalCheckBox.setText("apply globally");

        takeCheckBox.setText("take from selection");

        imageSplitPane.setDividerLocation(500);

        javax.swing.GroupLayout internalLayout = new javax.swing.GroupLayout(internal);
        internal.setLayout(internalLayout);
        internalLayout.setHorizontalGroup(
            internalLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(internalLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(internalLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(imageSplitPane)
                    .addComponent(jPanel3, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, internalLayout.createSequentialGroup()
                        .addComponent(UndoButton, javax.swing.GroupLayout.PREFERRED_SIZE, 120, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(takeCheckBox)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(globalCheckBox)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(SendButton, javax.swing.GroupLayout.PREFERRED_SIZE, 146, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(SaveButton, javax.swing.GroupLayout.PREFERRED_SIZE, 143, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(internalLayout.createSequentialGroup()
                        .addComponent(tabTitle, javax.swing.GroupLayout.PREFERRED_SIZE, 210, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(0, 0, Short.MAX_VALUE)))
                .addContainerGap())
        );
        internalLayout.setVerticalGroup(
            internalLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(internalLayout.createSequentialGroup()
                .addComponent(tabTitle)
                .addGap(3, 3, 3)
                .addComponent(jPanel3, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(imageSplitPane, javax.swing.GroupLayout.DEFAULT_SIZE, 354, Short.MAX_VALUE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(internalLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(SaveButton, javax.swing.GroupLayout.PREFERRED_SIZE, 29, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(SendButton)
                    .addComponent(UndoButton)
                    .addComponent(globalCheckBox)
                    .addComponent(takeCheckBox))
                .addContainerGap())
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(internal, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(internal, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
    }// </editor-fold>//GEN-END:initComponents

    private void UndoButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_UndoButtonActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_UndoButtonActionPerformed

    private void SaveButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_SaveButtonActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_SaveButtonActionPerformed

    private void SendButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_SendButtonActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_SendButtonActionPerformed


    // Variables declaration - do not modify//GEN-BEGIN:variables
    protected javax.swing.JLabel FuzzyText2;
    protected javax.swing.JLabel FuzzyUMaxText2;
    protected javax.swing.JLabel FuzzyUMiddleText2;
    protected javax.swing.JLabel FuzzyUMinText2;
    protected javax.swing.JSlider FuzzyUSlider;
    protected javax.swing.JSpinner FuzzyUSpinner;
    protected javax.swing.JLabel FuzzyUText2;
    protected javax.swing.JLabel FuzzyVMaxText2;
    protected javax.swing.JLabel FuzzyVMiddleText2;
    protected javax.swing.JLabel FuzzyVMinText2;
    protected javax.swing.JSlider FuzzyVSlider;
    protected javax.swing.JSpinner FuzzyVSpinner;
    protected javax.swing.JLabel FuzzyVText2;
    protected javax.swing.JButton SaveButton;
    protected javax.swing.JButton SendButton;
    protected javax.swing.JButton UndoButton;
    protected javax.swing.JLabel Y0Text2;
    protected javax.swing.JSlider Y0USlider;
    protected javax.swing.JSpinner Y0USpinner;
    protected javax.swing.JLabel Y0UText2;
    protected javax.swing.JSlider Y0VSlider;
    protected javax.swing.JSpinner Y0VSpinner;
    protected javax.swing.JLabel Y0VText2;
    protected javax.swing.JLabel Y255Text2;
    protected javax.swing.JLabel Y255UMaxText2;
    protected javax.swing.JLabel Y255UMiddleText2;
    protected javax.swing.JLabel Y255UMinText2;
    protected javax.swing.JSlider Y255USlider;
    protected javax.swing.JSpinner Y255USpinner;
    protected javax.swing.JLabel Y255UText2;
    protected javax.swing.JLabel Y255VMaxText2;
    protected javax.swing.JLabel Y255VMiddleText2;
    protected javax.swing.JLabel Y255VMinText2;
    protected javax.swing.JSlider Y255VSlider;
    protected javax.swing.JSpinner Y255VSpinner;
    protected javax.swing.JLabel Y255VText2;
    protected javax.swing.JCheckBox globalCheckBox;
    protected javax.swing.JSplitPane imageSplitPane;
    protected javax.swing.JPanel internal;
    protected javax.swing.JLabel jLabel13;
    protected javax.swing.JLabel jLabel14;
    protected javax.swing.JLabel jLabel15;
    protected javax.swing.JLabel jLabel16;
    protected javax.swing.JLabel jLabel17;
    protected javax.swing.JLabel jLabel18;
    protected javax.swing.JPanel jPanel3;
    protected javax.swing.JPanel jPanelFuzzy2;
    protected javax.swing.JPanel jPanelY2;
    protected javax.swing.JPanel jPanelY257;
    protected javax.swing.JLabel tabTitle;
    protected javax.swing.JCheckBox takeCheckBox;
    // End of variables declaration//GEN-END:variables
}