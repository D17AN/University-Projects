using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;
using System.Data.SqlClient;
namespace Main
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string conString= "Data Source = DESKTOP-H7HR5EA;" +
                "Initial Catalog = Supplement Sportive Company; Integrated Security = true;";
            SqlConnection con = new SqlConnection(conString);
            con.Open();
            //
            string strProduct = "SELECT * FROM PRODUCT";//PRODUCT(PID, TYPE, DESCRIPTION, PRICE, NAME)
            SqlCommand cmd = new SqlCommand(strProduct, con);
            using (SqlDataReader reader = cmd.ExecuteReader())
            {
                while (reader.Read())
                {
                    Console.WriteLine("{0}, {1}, {2}, {3}, {4}", reader[0], reader[1], reader[2], reader[3], reader[4]);
                }

            }
            con.Close();
            //Console.WriteLine("Hello World!");        
        }
    }
}
