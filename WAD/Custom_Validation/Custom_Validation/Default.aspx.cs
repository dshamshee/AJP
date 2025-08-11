using System;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Custom_Validation
{
    public partial class _Default : Page
    {
        protected void cvUsername_ServerValidate(object source, ServerValidateEventArgs args)
        {
            // Validate length only if not empty
            if (!string.IsNullOrWhiteSpace(args.Value) && args.Value.Length >= 5)
            {
                args.IsValid = true;
            }
            else
            {
                args.IsValid = false;
            }
        }

        protected void btnSubmit_Click(object sender, EventArgs e)
        {
            if (Page.IsValid)
            {
                Response.Write("Validation Successful! Username: " + txtUsername.Text);
            }
            else
            {
                Response.Write("Please enter valid Username");
            }
        }
    }
}
