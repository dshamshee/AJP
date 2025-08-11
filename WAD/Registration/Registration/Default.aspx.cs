using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Registration
{
    public partial class _Default : Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            // Optional logic here
        }

        protected void btnSubmit_Click(object sender, EventArgs e)
        {
            string name = txtName.Text.Trim();
            string dob = txtDOB.Text.Trim();
            string gender = rdoMale.Checked ? "Male" : rdoFemale.Checked ? "Female" : "Not specified";
            string email = txtEmail.Text.Trim();
            string contact = txtContact.Text.Trim();

            lblResult.Text = "Registration Details:<br/>" +
                             $"Name: {name}<br/>" +
                             $"DOB: {dob}<br/>" +
                             $"Gender: {gender}<br/>" +
                             $"Email: {email}<br/>" +
                             $"Contact No: {contact}";
        }
    }
}