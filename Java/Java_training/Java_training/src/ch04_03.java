
class Song{
	private String title, artist, country;
    private int year;
    
    public Song(String title, String artist, int year, String country) {
    	this.title = title;
    	this.artist = artist;
    	this.year = year;
    	this.country = country;
    }
    
    public void show() {
    	System.out.println("�뷡 ���� : " + this.title);
        System.out.println("���� : " + this.artist);
        System.out.println("���� : " + this.year);
        System.out.println("���� : " + this.country);
    	
    }
}

public class ch04_03 {
	public static void main(String[] args) {
	Song song = new Song("Dancing Queen", "ABBA", 1978, "������������");
	song.show();
	}
}