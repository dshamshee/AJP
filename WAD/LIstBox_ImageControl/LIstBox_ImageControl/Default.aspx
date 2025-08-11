<%@ Page Title="Home Page" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="LIstBox_ImageControl._Default" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">

    <main>
         <div style="text-align: center; margin-top: 50px">
        <h2>Fruit Image Viewer</h2>

        <asp:ListBox
          ID="lstFruits"
          runat="server"
          AutoPostBack="True"
          OnSelectedIndexChanged="lstFruits_SelectedIndexChanged"
        >
          <asp:ListItem Text="Apple" Value="apple.jpg" />
          <asp:ListItem Text="Banana" Value="banana.jpg" />
          <asp:ListItem Text="Mango" Value="mango.jpg" />
          <asp:ListItem Text="Orange" Value="orange.jpg" />
        </asp:ListBox>

        <br /><br />

        <asp:Image ID="imgFruit" runat="server" Width="200px" Height="200px" />

        <br /><br />

        <asp:Label ID="lblMessage" runat="server" Font-Bold="true" />
      </div>
    </main>

</asp:Content>
