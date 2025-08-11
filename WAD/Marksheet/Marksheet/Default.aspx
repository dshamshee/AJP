<%@ Page Title="Home Page" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="Marksheet._Default" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">

    <main>
        
        <table>
            <tr><td>Enrollment No:</td><td><asp:TextBox ID="txtEnroll" runat="server"></asp:TextBox></td></tr>
            <tr><td>Name:</td><td><asp:TextBox ID="txtName" runat="server"></asp:TextBox></td></tr>
            <tr><td>Subject 1:</td><td><asp:TextBox ID="txtSub1" runat="server"></asp:TextBox></td></tr>
            <tr><td>Subject 2:</td><td><asp:TextBox ID="txtSub2" runat="server"></asp:TextBox></td></tr>
            <tr><td>Subject 3:</td><td><asp:TextBox ID="txtSub3" runat="server"></asp:TextBox></td></tr>
            <tr><td>Subject 4:</td><td><asp:TextBox ID="txtSub4" runat="server"></asp:TextBox></td></tr>
            <tr><td>Subject 5:</td><td><asp:TextBox ID="txtSub5" runat="server"></asp:TextBox></td></tr>
            <tr><td colspan="2"><asp:Button ID="btnCalculate" runat="server" Text="Calculate" OnClick="btnCalculate_Click" /></td></tr>
        </table>
        <asp:Label ID="lblResult" runat="server" ForeColor="Blue"></asp:Label>
   
    </main>

</asp:Content>
