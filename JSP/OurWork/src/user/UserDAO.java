package user;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class UserDAO {
	// dao : �����ͺ��̽� ���� ��ü�� ���ڷμ�
	// ���������� db���� ȸ������ �ҷ����ų� db�� ȸ������ ������

	private Connection conn; // connection:db�������ϰ� ���ִ� ��ü
	private PreparedStatement pstmt;
	private ResultSet rs;
	
	// mysql�� ������ �ִ� �κ�
	public void conn() { // ������ ����ɶ����� �ڵ����� db������ �̷�� �� �� �ֵ�����
		conn = null;
		try {
			String url = "jdbc:mysql://elijahlee.iptime.org:3306/test";
			String user = "root";
			String password = "root";

			Class.forName("com.mysql.jdbc.Driver");
			conn = DriverManager.getConnection(url, user, password);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	// �α����� �õ��ϴ� �Լ�****
	public int login(String id, String passwd){
		rs = null;
		pstmt = null;
		String SQL = "SELECT passwd FROM accounts WHERE id=?";
		try {
			pstmt = conn.prepareStatement(SQL);
			pstmt.setString(1, id);
			rs = pstmt.executeQuery();
			if (rs.next()) {
				// �н����� ��ġ�Ѵٸ� ����
				if (rs.getString(1).equals(passwd)) {
					return 1; // �α��� ����
				} else
					return 0; // ��й�ȣ ����ġ
			}
			return -1; // ���̵� ���� ����
		} catch (Exception e) {
			e.printStackTrace();
		} 
		return -2; // �����ͺ��̽� ������ �ǹ�
	}
	
	public int SignUp(User user) throws SQLException {
		pstmt= null;
		int result = -1;
		String SQL = "INSERT INTO accounts VALUES (?,?,?,?,?);";
		try {
			pstmt = conn.prepareStatement(SQL);
			pstmt.setString(1, user.getId());
			pstmt.setString(2, user.getName());
			pstmt.setString(3, user.getPasswd());
			pstmt.setString(4, user.getEmail());
			pstmt.setString(5, user.getIntroduce());
			result = pstmt.executeUpdate();
		} catch (Exception e) {
			e.printStackTrace();
		}finally {
			if (pstmt != null)
				pstmt.close();
			if (conn != null)
				conn.close();
		}
		return result;
	}
}