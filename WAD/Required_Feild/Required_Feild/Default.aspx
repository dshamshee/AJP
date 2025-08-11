<%@ Page Title="Home Page" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="Required_Feild._Default" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">

    <main>
        <div style="text-align:center">
            <h2>Required Field Validator Example</h2>

            Enter Name: <asp:TextBox ID="txtName" runat="server" /><br />
            <asp:RequiredFieldValidator ID="rfvName" runat="server" 
                ControlToValidate="txtName"
                ErrorMessage="Name is required!" ForeColor="Red" /><br /><br />

            <asp:Button ID="btnSubmit" runat="server" Text="Submit" OnClick="btnSubmit_Click" /><br /><br />

            <asp:Label ID="lblMessage" runat="server" Font-Bold="true" ForeColor="Green" />
        </div>
    </main>

</asp:Content>
