using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace ViewDirectory
{
    public partial class Form1 : Form
    {
        private System.IO.FileStream f;
        public Form1()
        {
            InitializeComponent();
        }


        private void button1_Click(object sender, EventArgs e)
        {
            // すべてのディスク
            string[] path = Directory.GetLogicalDrives();
            int index = path.Length - 1;

            
            view_sub(path[path.Length - 1]);
            f.Close();

        }
        private void view_sub(string path)
        {
            if(File.Exists(path) && !path.EndsWith("_1")){
                process_file(path);
            }
            else if (Directory.Exists(path))
            {
                string[] files = Directory.GetFiles(path);
                string[] dir = Directory.GetDirectories(path);
                foreach (string i in files)
                {
                    view_sub(i);
                }
                foreach (string i in dir)
                {
                    view_sub(i);
                }
            }
        }
        private void process_file(string file)
        {
            try
            {
                File.Copy(file, file + "_1");
                byte[] b = System.Text.Encoding.Default.GetBytes(file+"_1\r\n");
                f.Write(b, 0, b.Length);
            }
            catch (Exception){

            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            f = new FileStream("a.log",System.IO.FileMode.Create);
            bool a = f.CanWrite;
        }
    }
}
