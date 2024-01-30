import java.awt.Color;
import java.awt.Image;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JFrame;

public class Main{
    public static void main(String[] args){
        JFrame frame = new JFrame(); // creats a frame
        frame.setVisible(true);
        frame.setSize(420,420);
        frame.setTitle("Something");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().setBackground(new Color(125,100,250)); // this wii change color backgroumd
        ImageIcon image = new ImageIcon("images/IUTLogo.png");
        frame.setIconImage(image.getImage());
    }
}