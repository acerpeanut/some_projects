using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using EnvDTE;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
        }
        void CommandWinExample(_DTE dte){
            Window win = dte.Windows.Item(EnvDTE.Constants.vsWindowKindCommandWindow);
            CommandWindow CW = (CommandWindow)win.Object;

            CW.SendInput("nav http://www.microsoft.com", true);

            CW.OutputString("This URL takes you to the main Microsoft website.");

            MessageBox.Show("Clearing the Command window...");
            CW.Clear();
    }
}
