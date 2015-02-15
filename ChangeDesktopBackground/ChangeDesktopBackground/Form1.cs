using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.Timers;

namespace ChangeDesktopBackground
{
    public partial class Form1 : Form
    {
        [DllImport("user32.dll", EntryPoint = "SystemParametersInfoA")]
        private static extern Int32 SystemParametersInfo(Int32 uAction, Int32 uParam, string lpvparam, Int32 fuwinIni);

        private Bitmap drawPaper;
        private System.Timers.Timer t;
        private int index;
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            changeBackground("701.out");
            /*if (t.Enabled)
            {
                t.Enabled = false;
            }
            else
            {
                t.Enabled = true;
            }*/
            
        }
        private void changeBackground( string filename) {
            System.IO.FileStream a = new System.IO.FileStream("peanut_bmp/" + filename, System.IO.FileMode.Open);
            int red, green, blue, ly, lu, lv;
            int w, h;
            int[] Y = new int[407040];
            int[] U = new int[101760];
            int[] V = new int[101760];
            for (int i = 0; i < 407040; i++)
            {
                Y[i] = a.ReadByte();
            }
            for (int i = 0; i < 101760; i++)
                U[i] = a.ReadByte();
            for (int i = 0; i < 101760; i++)
                V[i] = a.ReadByte();
            a.Close();
            for (int j = 0; j < 480; j++)
            {
                for (int i = 0; i < 848; i++)
                {
                    ly = Y[drawPaper.Width * j + i];
                    lu = U[(drawPaper.Width / 2) * (j / 2) + (i) / 2];
                    lv = V[(drawPaper.Width / 2) * (j / 2) + (i) / 2];
                    red = (int)(ly + 1.402 * (lv - 128));
                    green = (int)(ly - 0.34414 * (lu - 128) - 0.71414 * (lv - 128));
                    blue = (int)(ly + 1.772 * (lu - 128));
                    red = cut_256(red);
                    green = cut_256(green);
                    blue = cut_256(blue);
                    w = i - 5;
                    h = j - 5;
                    if (w >= 0 && w < 800 && h >= 0 && h < 460)
                    {
                        drawPaper.SetPixel(w, h, Color.FromArgb(100, ly, ly, ly));
                    }
                }
            }
            drawPaper.Save("vest_2.bmp", System.Drawing.Imaging.ImageFormat.Bmp);
            SystemParametersInfo(20, 1, "vest_2.bmp", 1);
        }
        private int cut_256(int c)
        {
            if (c < 0) c = 0;
            if (c > 255) c = 255;
            return c;
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            drawPaper = new Bitmap(848, 480);
            t = new System.Timers.Timer(800);
            index = 0;
            t.Elapsed += new ElapsedEventHandler(t_Elapsed);
            t.Enabled = false;
            this.ShowInTaskbar = false;
        }

        void t_Elapsed(object sender, ElapsedEventArgs e)
        {
            index = (index + 2) % 6120;
            changeBackground(index.ToString() + ".out");
        }
    }
}
