import java.awt.Color;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.Image;
import javax.imageio.ImageIO;
import javax.swing.ImageIcon;



public class frame1 extends JFrame {
    frame1() {
        ImageIcon image1 = new ImageIcon("enjoing_coding.jpeg");
        ImageIcon image = new ImageIcon("IUTLogo.png");
        JLabel label1 = new JLabel(); // adds lebel
        label1.setText("Coding is so much fun");     // adds text to the lebel

        
        label1.setIcon(image1);


        this.setVisible(true);
        this.setSize(420, 420);
        this.setTitle("Something");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.getContentPane().setBackground(new Color(125, 100, 250)); // this wii change color backgroumd
        
        this.setIconImage(image.getImage());
        this.add(label1);


    }
}
