<%@ Page Title="Home Page" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="Custom_Validation._Default" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">
    <main>
        <asp:Label ID="lblInput" runat="server" Text="Enter Username:"></asp:Label>
        <asp:TextBox ID="txtUsername" runat="server"></asp:TextBox>

        <!-- Required field validator -->
        <asp:RequiredFieldValidator 
            ID="rfvUsername" 
            runat="server" 
            ControlToValidate="txtUsername"
            ErrorMessage="Username is required."
            ForeColor="Red" 
            Display="Dynamic">*</asp:RequiredFieldValidator>

        <!-- Custom length validator -->
        <asp:CustomValidator 
            ID="cvUsername" 
            runat="server" 
            ControlToValidate="txtUsername"
            ErrorMessage="Username must be at least 5 characters long."
            OnServerValidate="cvUsername_ServerValidate" 
            ForeColor="Red" 
            Display="Dynamic">*</asp:CustomValidator>

        <br /><br />

        <asp:Button ID="btnSubmit" runat="server" Text="Submit" OnClick="btnSubmit_Click" />
    </main>
</asp:Content>
