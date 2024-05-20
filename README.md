<?xml version="1.0" encoding="utf-8"?>
<configuration>
  <connectionStrings>
    <add name="CIMSConnectionString" connectionString="server=(localdb)\local;Initial Catalog=CIMS;Integrated Security=True" providerName="System.Data.SqlClient" />
  </connectionStrings>
  
  <system.web>
    <compilation debug="true" targetFramework="4.7.2" />
    <httpRuntime targetFramework="4.7.2" />
    <sessionState mode="SQLServer" sqlConnectionString="server=(localdb)\local;database=CIMS;integrated security=true" allowCustomSqlDatabase="true" />
    
    <pages>
      <namespaces>
        <add namespace="System.Web.Optimization" />
      </namespaces>
      <controls>
        <add assembly="Microsoft.AspNet.Web.Optimization.WebForms" namespace="Microsoft.AspNet.Web.Optimization.WebForms" tagPrefix="webopt" />
      </controls>
    </pages>
  </system.web>
  
  <runtime>
    <assemblyBinding xmlns="urn:schemas-microsoft-com:asm.v1">
      <dependentAssembly>
        <assemblyIdentity name="Antlr3.Runtime" publicKeyToken="eb42632606e9261f" />
        <bindingRedirect oldVersion="0.0.0.0-3.5.0.2" newVersion="3.5.0.2" />
      </dependentAssembly>
      <dependentAssembly>
        <assemblyIdentity name="Microsoft.Web.Infrastructure" publicKeyToken="31bf3856ad364e35" />
        <bindingRedirect oldVersion="0.0.0.0-2.0.1.0" newVersion="2.0.1.0" />
      </dependentAssembly>
      <dependentAssembly>
        <assemblyIdentity name="Newtonsoft.Json" publicKeyToken="30ad4fe6b2a6aeed" />
        <bindingRedirect oldVersion="0.0.0.0-13.0.0.0" newVersion="13.0.0.0" />
      </dependentAssembly>
      <dependentAssembly>
        <assemblyIdentity name="WebGrease" publicKeyToken="31bf3856ad364e35" />
        <bindingRedirect oldVersion="0.0.0.0-1.6.5135.21938" newVersion="1.6.5135.21938" />
      </dependentAssembly>
    </assemblyBinding>
  </runtime>
  
  <system.codedom>
    <compilers>
      <compiler language="c#;cs;csharp" extension=".cs" type="Microsoft.CodeDom.Providers.DotNetCompilerPlatform.CSharpCodeProvider, Microsoft.CodeDom.Providers.DotNetCompilerPlatform" />
      <compiler language="vb;vbs;visualbasic;vbscript" extension=".vb" type="Microsoft.CodeDom.Providers.DotNetCompilerPlatform.VBCodeProvider, Microsoft.CodeDom.Providers.DotNetCompilerPlatform" />
    </compilers>
  </system.codedom>
</configuration>
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

<%@ Master Language="C#" AutoEventWireup="true" CodeBehind="CIMS_Site.master.cs" Inherits="CarInfoMgmtSystem.CIMS_Site" %>

<!DOCTYPE html>
<html lang="en">
<head runat="server">
    <meta charset="utf-8" />
    <title><asp:ContentPlaceHolder ID="head" runat="server"></asp:ContentPlaceHolder> - Car Information Management System</title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <header>
                <h1>Car Information Management System</h1>
                <nav>
                    <ul>
                        <li><a href="Default.aspx">Home</a></li>
                        <li><a href="Admin.aspx">Admin</a></li>
                        <li><a href="Customer.aspx">Customer</a></li>
                    </ul>
                </nav>
            </header>
            <hr />
            <asp:ContentPlaceHolder ID="ContentPlaceHolder1" runat="server"></asp:ContentPlaceHolder>
            <hr />
            <footer>
                <p>&copy; <%: DateTime.Now.Year %> - Car Information Management System</p>
            </footer>
        </div>
    </form>
</body>
</html>



-------------------------------------------------------------------------------------------------------------------------------------------------


HTTP Error 403.14 - Forbidden
The Web server is configured to not list the contents of this directory.

Most likely causes:
A default document is not configured for the requested URL, and directory browsing is not enabled on the server.

Things you can try:
If you do not want to enable directory browsing, ensure that a default document is configured and that the file exists.
Enable directory browsing.
Go to the IIS Express install directory.
Run appcmd set config /section:system.webServer/directoryBrowse /enabled:true to enable directory browsing at the server level.
Run appcmd set config ["SITE_NAME"] /section:system.webServer/directoryBrowse /enabled:true to enable directory browsing at the site level.
Verify that the configuration/system.webServer/directoryBrowse@enabled attribute is set to true in the site or application configuration file.

Detailed Error Information:
Module	   DirectoryListingModule
Notification	   ExecuteRequestHandler
Handler	   StaticFile
Error Code	   0x00000000
Requested URL	   https://localhost:44301/
Physical Path	   C:\src\C#\CarInformationMgmtSystem\CarInfoMgmtSystem
Logon Method	   Anonymous
Logon User	   Anonymous

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Login.aspx.cs


using System;
using System.Web.UI;
using LoginApp.DAL;

namespace LoginApp
{
    public partial class Login : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
        }

        protected void btnLogin_Click(object sender, EventArgs e)
        {
            string username = txtUsername.Text;
            string password = txtPassword.Text;

            if (username == "admin" && password == "admin") // Simplified admin login for demonstration
            {
                Session["Username"] = username;
                Session["Role"] = "Admin";
                Response.Redirect("Admin.aspx");
            }
            else
            {
                UserDAL userDAL = new UserDAL();
                bool isValidUser = userDAL.ValidateUser(username, password);

                if (isValidUser)
                {
                    Session["Username"] = username;
                    Session["Role"] = "Customer";
                    Response.Redirect("Customer.aspx");
                }
                else
                {
                    lblMessage.Text = "Invalid username or password.";
                }
            }
        }
    }
}

--------------------------------------------------------------------------------------------------------------------------------------------------------------


Admin.aspx  (Web Form)

<%@ Page Title="Admin" Language="C#" MasterPageFile="~/Site.master" AutoEventWireup="true" CodeBehind="Admin.aspx.cs" Inherits="LoginApp.Admin" %>

<asp:Content ID="Content1" ContentPlaceHolderID="MainContent" runat="server">
    <h2>Admin Page</h2>
    <p>Welcome, Admin!</p>
    <!-- Add UI for managing cars (CRUD operations) -->
</asp:Content>


---------------------------------------------------------------------------------------------------------------------------------------------------------
Cutomer.aspx


<%@ Page Title="Customer" Language="C#" MasterPageFile="~/Site.master" AutoEventWireup="true" CodeBehind="Customer.aspx.cs" Inherits="LoginApp.Customer" %>

<asp:Content ID="Content1" ContentPlaceHolderID="MainContent" runat="server">
    <h2>Customer Page</h2>
    <p>Welcome, Customer!</p>
    <!-- Add UI for searching and viewing car details -->
</asp:Content>

---------------------------------------------------------------------------------------------------------------------------------------------------------

Admin.aspx.cs


using System;
using LoginApp.DAL;

namespace LoginApp
{
    public partial class Admin : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["Role"] == null || Session["Role"].ToString() != "Admin")
            {
                Response.Redirect("Login.aspx");
            }
        }

        // Add methods for handling CRUD operations
    }
}


-----------------------------------------------------------------------------------------------------------------------------------------------------------


Customer.aspx.cs




using System;

namespace LoginApp
{
    public partial class Customer : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["Role"] == null || Session["Role"].ToString() != "Customer")
            {
                Response.Redirect("Login.aspx");
            }
        }

        // Add methods for searching and viewing car details
    }
}


-----------------------------------------------------------------------------------------------------------------------------------------------------------------------


Output Caching (Add output caching to the methods that display search results.)


using System;
using System.Web.UI;

namespace LoginApp
{
    public partial class Customer : Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["Role"] == null || Session["Role"].ToString() != "Customer")
            {
                Response.Redirect("Login.aspx");
            }
        }

        [OutputCache(Duration = 60, VaryByParam = "none")]
        public DataTable GetCachedCarsByManufacturerAndType(string manufacturerName, string type)
        {
            CarDAL carDAL = new CarDAL();
            return carDAL.GetCarsByManufacturerAndType(manufacturerName, type);
        }

        // Add methods for displaying search results
    }
}



-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Example method for fetching and displaying car details:



using System;
using System.Data;

namespace LoginApp
{
    public partial class Customer : Page
    {
        protected void btnSearch_Click(object sender, EventArgs e)
        {
            string manufacturerName = txtManufacturerName.Text;
            string type = ddlCarType.SelectedValue;
            DataTable dt = GetCachedCarsByManufacturerAndType(manufacturerName, type);

            // Bind the results to a GridView or other UI control
            gvCarResults.DataSource = dt;
            gvCarResults.DataBind();
        }
    }
}
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


DBMS tables(OLD)

use [CarInfoMgmtSys]

--Create Car Table with Foreign Key Constraints

create table Car(

CarId int primary key,

ManufacturerName nvarchar(100),
Model nvarchar(100) unique,
Type nvarchar(50),
Engine nvarchar(4) check(Engine LIKE '[0-9].[0-9]L'),
BHP int,
TransmissionId int,
Mileage int,
Seats int,
AirBagDetails nvarchar(255),
BootSpace int,
Price decimal(18,2),
);


--Create Manufacturer Table

create table Manufacturer(
ManufacturingId int primary key,
--CarId int,
Name nvarchar(100),
ContactNo char(10) CHECK(LEN(ContactNo)=10),
RegisteredOffice nvarchar(255)
);


--Create CarType Table

create table CarType(
CarTypeId int primary key,
--CarId int,
Type nvarchar(50),
);


--Create CarTransmissionType Table

create table CarTransmissionType(
TransmissionId int primary key,
--CarId int,
Type nvarchar(50)
);





















