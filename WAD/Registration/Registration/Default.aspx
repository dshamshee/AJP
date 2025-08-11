<%@ Page Title="Home Page" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="Registration._Default" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">

    <main>
        <div style="text-align:center; padding: 20px;">
            <h2>User Registration Form</h2>

            <asp:Label ID="lblName" runat="server" Text="Name:" AssociatedControlID="txtName" /><br />
            <asp:TextBox ID="txtName" runat="server" /><br /><br />

            <asp:Label ID="lblDOB" runat="server" Text="Date of Birth (MM/DD/YYYY):" AssociatedControlID="txtDOB" /><br />
            <asp:TextBox ID="txtDOB" runat="server" /><br /><br />

            <asp:Label ID="lblGender" runat="server" Text="Gender:" /><br />
            <asp:RadioButton ID="rdoMale" runat="server" GroupName="Gender" Text="Male" />
            <asp:RadioButton ID="rdoFemale" runat="server" GroupName="Gender" Text="Female" /><br /><br />

            <asp:Label ID="lblEmail" runat="server" Text="Email:" AssociatedControlID="txtEmail" /><br />
            <asp:TextBox ID="txtEmail" runat="server" /><br /><br />

            <asp:Label ID="lblContact" runat="server" Text="Contact No:" AssociatedControlID="txtContact" /><br />
            <asp:TextBox ID="txtContact" runat="server" /><br /><br />

            <asp:Button ID="btnSubmit" runat="server" Text="Submit" OnClick="btnSubmit_Click" /><br /><br />

            <asp:Label ID="lblResult" runat="server" Font-Bold="true" ForeColor="Blue" />
        </div>
    </main>

</asp:Content>
