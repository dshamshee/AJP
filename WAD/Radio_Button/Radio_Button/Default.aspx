<%@ Page Title="Home Page" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="Radio_Button._Default" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">

    <main>
                <h3>Select Gender:</h3>
        <asp:RadioButton ID="rbMale" runat="server" GroupName="Gender" Text="Male" />
        <asp:RadioButton ID="rbFemale" runat="server" GroupName="Gender" Text="Female" />
        <br /><br />
        <asp:Button ID="btnShowGender" runat="server" Text="Show Gender" OnClick="btnShowGender_Click" />
        <br /><br />
        <asp:Label ID="lblGender" runat="server" Font-Bold="True" ForeColor="Blue"></asp:Label>
    </main>

</asp:Content>
