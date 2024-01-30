import java.awt.Color;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class frame1 extends JFrame {
    frame1() {
        
        JLabel label1 = new JLabel(); // adds lebel
        label1.setText("Coding is so much fun");     // adds text to the lebel



        this.setVisible(true);
        this.setSize(420, 420);
        this.setTitle("Something");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.getContentPane().setBackground(new Color(125, 100, 250)); // this wii change color backgroumd
        ImageIcon image = new ImageIcon("images/IUTLogo.png");
        this.setIconImage(image.getImage());
        this.add(label1);

    }
}
