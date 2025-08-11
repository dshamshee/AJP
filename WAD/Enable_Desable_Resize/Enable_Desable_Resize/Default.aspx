<%@ Page Title="Home Page" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="Enable_Desable_Resize._Default" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">

    <main>
                <div style="margin: 50px;">
            <asp:TextBox ID="txtDemo" runat="server" Width="200px"></asp:TextBox><br /><br />
            <asp:Button ID="btnEnable" runat="server" Text="Enable TextBox" OnClick="btnEnable_Click" />
            <asp:Button ID="btnDisable" runat="server" Text="Disable TextBox" OnClick="btnDisable_Click" />
            <asp:Button ID="btnResize" runat="server" Text="Change Width" OnClick="btnResize_Click" />
        </div>
    </main>

</asp:Content>
