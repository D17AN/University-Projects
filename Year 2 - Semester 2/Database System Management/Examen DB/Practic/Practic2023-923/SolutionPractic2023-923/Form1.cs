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

namespace SolutionPractic2023_923
{
    public partial class Form1 : Form
    {
        SqlConnection conn;
        SqlDataAdapter daSports; // for table CUSTOMER (parent table)
        SqlDataAdapter daPlayers; // for table ORDER_ (child table)
        DataSet dset;
        BindingSource bsSports;
        BindingSource bsPlayers;

        SqlCommandBuilder cmdBuilder; // add, insert, delete

        string querySports;
        string queryPlayers;


        public Form1()
        {
            InitializeComponent();
            FillData();
        }

        string GetConnectionString()
        {
            return "Data Source = DESKTOP-H7HR5EA;" +
                "Initial Catalog = SportPerformances; Integrated Security = true;";

        }
        void FillData()
        {
            //SQL Connection
            conn = new SqlConnection(GetConnectionString());

            querySports = "SELECT * FROM Sports";
            queryPlayers = "SELECT * FROM Players";


            //SQLDataAdapters (for parent table and child table), DataSet

            daSports = new SqlDataAdapter(querySports, conn);
            daPlayers = new SqlDataAdapter(queryPlayers, conn);
            dset = new DataSet();
            daSports.Fill(dset, "Sports");
            daPlayers.Fill(dset, "Players");

            cmdBuilder = new SqlCommandBuilder(daPlayers);

            dset.Relations.Add("SportsPlayers",
                dset.Tables["Sports"].Columns["id"],
                dset.Tables["Players"].Columns["sport_id"]);


            /*
            //fill data into DataGridView using the properties DataSource, DataMember
            sportsDataGridView.DataSource = dset.Tables["Sports"];
            playersDataGridView.DataSource = sportsDataGridView.DataSource;
            playersDataGridView.DataMember = "SportsPlayers";
            */
            //fill data in DataGridViews using Data Binding

            this.bsSports = new BindingSource();
            this.bsSports.DataSource = this.dset.Tables["Sports"];
            this.bsPlayers = new BindingSource(this.bsSports, "SportsPlayers");

            this.sportsDataGridView.DataSource = this.bsSports;
            this.playersDataGridView.DataSource = this.bsPlayers;

            cmdBuilder.GetUpdateCommand();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            daPlayers.Update(dset, "Players");
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void dataGridView1_CellContentClick_1(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}
