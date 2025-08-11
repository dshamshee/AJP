using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace LIstBox_ImageControl
{
    public partial class _Default : Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                lblMessage.Text = "Please select a fruit to view its image.";
            }
        }

        protected void lstFruits_SelectedIndexChanged(object sender, EventArgs e)
        {
            string selectedImage = lstFruits.SelectedValue;
            imgFruit.ImageUrl = "~/Images/" + selectedImage;
            lblMessage.Text = "You selected: " + lstFruits.SelectedItem.Text;
        }
    }
}