namespace A2
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.parentGridView = new System.Windows.Forms.DataGridView();
            this.childGridView = new System.Windows.Forms.DataGridView();
            this.updateCmdBuilder = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.parentGridView)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.childGridView)).BeginInit();
            this.SuspendLayout();
            // 
            // parentGridView
            // 
            this.parentGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.parentGridView.Location = new System.Drawing.Point(12, 21);
            this.parentGridView.Name = "parentGridView";
            this.parentGridView.RowHeadersWidth = 51;
            this.parentGridView.RowTemplate.Height = 24;
            this.parentGridView.Size = new System.Drawing.Size(700, 404);
            this.parentGridView.TabIndex = 0;
            this.parentGridView.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.parentGridView1_CellContentClick);
            // 
            // childGridView
            // 
            this.childGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.childGridView.Location = new System.Drawing.Point(767, 21);
            this.childGridView.Name = "childGridView";
            this.childGridView.RowHeadersWidth = 51;
            this.childGridView.RowTemplate.Height = 24;
            this.childGridView.Size = new System.Drawing.Size(700, 404);
            this.childGridView.TabIndex = 1;
            this.childGridView.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.childGridView_CellContentClick);
            // 
            // updateCmdBuilder
            // 
            this.updateCmdBuilder.Location = new System.Drawing.Point(649, 509);
            this.updateCmdBuilder.Name = "updateCmdBuilder";
            this.updateCmdBuilder.Size = new System.Drawing.Size(187, 70);
            this.updateCmdBuilder.TabIndex = 2;
            this.updateCmdBuilder.Text = "Update";
            this.updateCmdBuilder.UseVisualStyleBackColor = true;
            this.updateCmdBuilder.Click += new System.EventHandler(this.updateCmdBuilder_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1479, 708);
            this.Controls.Add(this.updateCmdBuilder);
            this.Controls.Add(this.childGridView);
            this.Controls.Add(this.parentGridView);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.parentGridView)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.childGridView)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView parentGridView;
        private System.Windows.Forms.DataGridView childGridView;
        private System.Windows.Forms.Button updateCmdBuilder;
    }
}

