using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;


namespace bitmap
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Bitmap a = new Bitmap("a.png");
            FileStream b = new FileStream("a.out", FileMode.Create);
            for (int i = 0; i < 128; i++)
            {
                for (int j = 0; j < 128; j++)
                {
                    Color d = a.GetPixel(i, j);
                    //byte c = 255;
                    b.WriteByte(d.R);
                    b.WriteByte(d.G);
                    b.WriteByte(d.B);
                }
            }
            b.Close();
            a.Dispose();
        }
    }
}
