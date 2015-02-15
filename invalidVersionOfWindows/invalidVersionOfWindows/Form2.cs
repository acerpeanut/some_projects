using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace invalidVersionOfWindows
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            int height1 = System.Windows.Forms.Screen.PrimaryScreen.Bounds.Height;
            int width1 = System.Windows.Forms.Screen.PrimaryScreen.Bounds.Width;
            int ys = height1 - this.DesktopBounds.Height;
            int xs = width1 - this.DesktopBounds.Width;
            this.SetDesktopLocation(xs, ys);
        }

        private void notifyIcon1_MouseDoubleClick(object sender, MouseEventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Hide();
            this.Close();
        }
    }
}
