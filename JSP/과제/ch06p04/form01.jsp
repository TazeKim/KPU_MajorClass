<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<html>
<head>
<title>Form Processing</title>
</head>
<body>
    <form action="form01_process.jsp" method="post">
        이름: <input type="text" name="name">
        <p> 주소: <input type="text" name="address">
        <p> 이메일: <input type="text" name="email">
        <p> 전송:<input type="submit" value="전송">
    </form>
</body>
</html>