using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace A1
{
    public partial class Form1 : Form
    {
        SqlConnection conn;
        SqlDataAdapter daCustomer; // for table CUSTOMER (parent table)
        SqlDataAdapter daOrder; // for table ORDER_ (child table)
        DataSet dset;
        BindingSource bsCustomer;
        BindingSource bsOrder;

        SqlCommandBuilder cmdBuilder; // add, insert, delete

        string queryCustomer;
        string queryOrder;

        public Form1()
        {
            InitializeComponent();
            FillData();
        }

        string GetConnectionString()
        {
            return "Data Source = DESKTOP-H7HR5EA;" +
                "Initial Catalog = Supplement Sportive Company; Integrated Security = true;";

        }
        void FillData()
        {
            //SQL Connection
            conn = new SqlConnection(GetConnectionString());

            queryCustomer = "SELECT * FROM CUSTOMER";
            queryOrder = "SELECT * FROM ORDER_";


            //SQLDataAdapters (for parent table and child table), DataSet
            
            daCustomer = new SqlDataAdapter(queryCustomer, conn);
            daOrder = new SqlDataAdapter(queryOrder, conn);
            dset = new DataSet();
            daCustomer.Fill(dset, "CUSTOMER");
            daOrder.Fill(dset, "ORDER_");

            cmdBuilder = new SqlCommandBuilder(daOrder);

            dset.Relations.Add("CustomerOrder", 
                dset.Tables["CUSTOMER"].Columns["CID"], 
                dset.Tables["ORDER_"].Columns["CID"]);

           
            /*
            //fill data into DataGridView using the properties DataSource, DataMember
            dataGridView1.DataSource = dset.Tables["CUSTOMER"];
            dataGridView2.DataSource = dataGridView1.DataSource;
            dataGridView2.DataMember = "CustomerOrder";
            */
            //fill data in DataGridViews using Data Binding
            
            this.bsCustomer = new BindingSource();
            this.bsCustomer.DataSource = this.dset.Tables["CUSTOMER"];
            this.bsOrder = new BindingSource(this.bsCustomer, "CustomerOrder");

            this.dataGridView1.DataSource = this.bsCustomer;
            this.dataGridView2.DataSource= this.bsOrder;
            
            cmdBuilder.GetUpdateCommand();

            
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            foreach(DataRow row in dset.Tables["ORDER_"].Rows)
            {
                try
                {
                    if (Convert.ToInt32(row["PRICE"]) <= 0)
                    {
                        MessageBox.Show("Price must be a positive integer!");
                        return;
                    }
                    if (Convert.ToString(row["DESCRIPTION"]).Length >= 100)
                    {
                        MessageBox.Show("Description must be a string with less than 100 characters!");
                        return;
                    }
                    if (Convert.ToInt32(row["OID"]) < 0)
                    {
                        MessageBox.Show("OID must be a positive integer!");
                        return;
                    }
                    if (Convert.ToInt32(row["CID"]) < 0)
                    {
                        MessageBox.Show("CID must be a positive integer!");
                    }
                }
                catch
                {
                    MessageBox.Show("Something bad happend when converting the data!");
                    return;
                }
            }
            daOrder.Update(dset, "ORDER_");
            
        }


        private void DataGridView2_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }


        private void Label1_Click(object sender, EventArgs e)
        {

        }

        private void Label2_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
