using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Enable_Desable_Resize
{
    public partial class _Default : Page
    {
        protected void btnEnable_Click(object sender, EventArgs e)
        {
            txtDemo.Enabled = true;
        }

        protected void btnDisable_Click(object sender, EventArgs e)
        {
            txtDemo.Enabled = false;
        }

        protected void btnResize_Click(object sender, EventArgs e)
        {
            txtDemo.Width = new System.Web.UI.WebControls.Unit(400);
        }
    }
}