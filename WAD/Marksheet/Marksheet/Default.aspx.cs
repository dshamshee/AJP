using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Marksheet
{
    public partial class _Default : Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnCalculate_Click(object sender, EventArgs e)
        {
            try
            {
                int sub1 = int.Parse(txtSub1.Text);
                int sub2 = int.Parse(txtSub2.Text);
                int sub3 = int.Parse(txtSub3.Text);
                int sub4 = int.Parse(txtSub4.Text);
                int sub5 = int.Parse(txtSub5.Text);

                int total = sub1 + sub2 + sub3 + sub4 + sub5;
                double average = total / 5.0;

                lblResult.Text = $"Total Marks: {total}, Average: {average:F2}";
            }
            catch (Exception ex)
            {
                lblResult.Text = $"Error: {ex.Message}";
            }
        }
    }
}