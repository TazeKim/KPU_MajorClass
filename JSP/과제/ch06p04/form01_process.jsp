<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<html>
<head>
<title>Form Processing</title>
</head>
<body>
    <%
        request.setCharacterEncoding("utf-8");
        String name=request.getParameter("name");
        String address=request.getParameter("address");
        String email=request.getParameter("email");
    %>
    <p> 아이디: <%=name %>
    <p> 주소: <%=address %>
    <p> 이메일: <%=email %>
</body>
</html>