using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Configuration;
using System.Data.SqlClient;
using System.Linq.Expressions;
using System.Collections.Specialized;
using System.Xml;
using System.IO.Ports;

namespace A2
{
    public partial class Form1 : Form
    {
        SqlConnection conn;

        SqlDataAdapter daParent; // for parent table
        SqlDataAdapter daChild; // for child table
        DataSet dset;

        BindingSource bsParent;
        BindingSource bsChild;

        SqlCommandBuilder cmdBuilder; // add, insert, delete

        string queryParent;
        string queryChild;

        public Form1()
        {
            InitializeComponent();
            FillData();
        }

        void FillData()
        {
            string con = ConfigurationManager.ConnectionStrings["cn"].ConnectionString;
            try
            {
                conn = new SqlConnection(con);
                string queryParent = ConfigurationManager.AppSettings["select"];
                string queryChild = ConfigurationManager.AppSettings["select_sub"];

                string parentName = ConfigurationManager.AppSettings["TableName"];
                string childName = ConfigurationManager.AppSettings["TableName_sub"];

                daParent = new SqlDataAdapter(queryParent, conn);
                daChild = new SqlDataAdapter(queryChild, conn);
                dset = new DataSet();
                daParent.Fill(dset, parentName);
                daChild.Fill(dset, childName);

                cmdBuilder = new SqlCommandBuilder(daChild);

                dset.Relations.Add("ParentChild",
                    dset.Tables[parentName].Columns[ConfigurationManager.AppSettings["PrimaryKeyName"]],
                    dset.Tables[childName].Columns[ConfigurationManager.AppSettings["ForeignKeyName"]]);

                bsParent = new BindingSource();
                bsParent.DataSource = dset.Tables[parentName];
                bsChild = new BindingSource(bsParent, "ParentChild");

                parentGridView.DataSource = bsParent;
                childGridView.DataSource = bsChild;

                cmdBuilder.GetUpdateCommand();

            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        private void updateCmdBuilder_Click(object sender, EventArgs e)
        {
            try
            {
                daChild.Update(dset, ConfigurationManager.AppSettings["TableName_sub"]);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
    
        }

        private void parentGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void childGridView_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
    }
}
