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

namespace Lab2
{
    public partial class Form1 : Form
    {
        SqlConnection conn;
        SqlDataAdapter daProduct;
        SqlDataAdapter daSomething;

        DataSet dset;
        BindingSource bsProduct;
        BindingSource bsSomething;

        SqlCommandBuilder cmdBuilder;
        string queryProduct;
        string querySomething;


        void fillData()
        {
            conn = new SqlConnection(getConnectionString());
            queryProduct = "SELECT *FROM PRODUCT";
            querySomething = "SELECT* FROM SOMETHING";

            daProduct = new SqlDataAdapter(queryProduct, conn);
            daSomething = new SqlDataAdapter(querySomething, conn);
            dset = new DataSet();
            daProduct.Fill(dset, "PRODUCT");
            daSomething.Fill(dset, "SOMETHING");
            cmdBuilder = new SqlCommandBuilder(daProduct);
            dset.Relations.Add("ProductSomething", dset.Tables["PRODUCT"].Columns["PID"], dset.Tables["SOMETHING"].Columns["ID_SOMETHING"]);
            this.dataGridView1.DataSource = dset.Tables["PRODUCT"];
            this.dataGridView2.DataSource = this.dataGridView1.DataSource;
            this.dataGridView2.DataMember = "ProductSomething";
            cmdBuilder.GetUpdateCommand();


        }

        string getConnectionString()
        {
            return "Data Source = DESKTOP-H7HR5EA;" +
                "Initial Catalog = Supplement Sportive Company; Integrated Security = true;";
        }
        public Form1()
        {
            InitializeComponent();
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            daProduct.Update(dset, "PRODUCT");
        }
    }
}
