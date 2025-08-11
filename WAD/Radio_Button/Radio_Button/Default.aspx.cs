using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Radio_Button
{
    public partial class _Default : Page
    {
        protected void btnShowGender_Click(object sender, EventArgs e)
        {
            if (rbMale.Checked)
                lblGender.Text = "Selected Gender: Male";
            else if (rbFemale.Checked)
                lblGender.Text = "Selected Gender: Female";
            else
                lblGender.Text = "Please select a gender.";
        }
    }
}