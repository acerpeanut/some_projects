using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Timers;
using System.Threading;

namespace invalidVersionOfWindows
{
    public partial class Form1 : Form
    {
        private Form2 sub;
        private System.Timers.Timer time;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //this.Shown += new EventHandler(Form1_Shown); 
            this.ShowInTaskbar = false;
            time = new System.Timers.Timer();
            time.Interval = 3600000;
            time.Elapsed += new ElapsedEventHandler(call_open);
            time.Enabled = true;
            //t = new Thread(new ThreadStart(this.thread_new));
            //t.Start();
            //this.button1_Click(null, null);
            //this.thread_new();

        }

        void Form1_Shown(object sender, EventArgs e)
        {
            //this.Visible = false;
            thread_new();
            //this.Hide();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            sub = new Form2();
            sub.Show();
            //t.Start();
        }

        private void call_open(object sender, ElapsedEventArgs e)
        {
            //sub.Hide();
            //this.button1_Click(null, null);
            thread_new();
        }
        private void thread_new()
        {
            Form2 tmpform = new Form2();
            Application.Run(tmpform);
        }
    }
}
