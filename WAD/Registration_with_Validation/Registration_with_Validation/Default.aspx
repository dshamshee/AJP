<%@ Page Title="Home Page" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="Registration_with_Validation._Default" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">

    <main>
       <asp:Label ID="lblName" runat="server" Text="Name:"></asp:Label>
<asp:TextBox ID="txtName" runat="server"></asp:TextBox>
<asp:RequiredFieldValidator ID="rfvName" runat="server" ControlToValidate="txtName" ErrorMessage="Name is required." ForeColor="Red">*</asp:RequiredFieldValidator>
<br />

<asp:Label ID="lblEmail" runat="server" Text="Email:"></asp:Label>
<asp:TextBox ID="txtEmail" runat="server"></asp:TextBox>
<asp:RegularExpressionValidator ID="revEmail" runat="server" ControlToValidate="txtEmail"
    ValidationExpression="\w+@[a-zA-Z_]+?\.[a-zA-Z]{2,6}" ErrorMessage="Invalid Email Format." ForeColor="Red">*</asp:RegularExpressionValidator>
<br />

<asp:Label ID="lblPassword" runat="server" Text="Password:"></asp:Label>
<asp:TextBox ID="txtPassword" runat="server" TextMode="Password"></asp:TextBox>
<asp:RequiredFieldValidator ID="rfvPassword" runat="server" ControlToValidate="txtPassword" ErrorMessage="Password is required." ForeColor="Red">*</asp:RequiredFieldValidator>
<br />

<asp:Label ID="lblConfirmPassword" runat="server" Text="Confirm Password:"></asp:Label>
<asp:TextBox ID="txtConfirmPassword" runat="server" TextMode="Password"></asp:TextBox>
<asp:CompareValidator ID="cvPassword" runat="server" ControlToCompare="txtPassword" ControlToValidate="txtConfirmPassword"
    ErrorMessage="Passwords do not match." ForeColor="Red">*</asp:CompareValidator>
<br />

<asp:Button ID="btnSubmit" runat="server" Text="Register" OnClick="btnSubmit_Click" />
<asp:ValidationSummary ID="vsSummary" runat="server" ForeColor="Red" />
    </main>

</asp:Content>
