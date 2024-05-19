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



