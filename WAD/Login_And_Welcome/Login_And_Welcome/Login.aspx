<%@ Page Title="Contact" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Login.aspx.cs" Inherits="Login_And_Welcome.Contact" %>

<asp:Content ID="Content1" ContentPlaceHolderID="MainContent" runat="server">
    <h2>Login</h2>
    <asp:Label ID="lblMessage" runat="server" ForeColor="Red"></asp:Label><br />
    Username: <asp:TextBox ID="txtUsername" runat="server"></asp:TextBox><br />
    Password: <asp:TextBox ID="txtPassword" runat="server" TextMode="Password"></asp:TextBox><br />
    <asp:Button ID="btnLogin" runat="server" Text="Login" OnClick="BtnLogin_Click" />
</asp:Content>
