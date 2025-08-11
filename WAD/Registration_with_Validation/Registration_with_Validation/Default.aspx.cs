using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Registration_with_Validation
{
    public partial class _Default : Page
    {
        protected void btnSubmit_Click(object sender, EventArgs e)
        {
            string name = txtName.Text;
            string email = txtEmail.Text;
            string password = txtPassword.Text;

            Response.Write("Registration Successful!<br/>");
            Response.Write("Name: " + name + "<br/>");
            Response.Write("Email: " + email + "<br/>");
        }
    }
}