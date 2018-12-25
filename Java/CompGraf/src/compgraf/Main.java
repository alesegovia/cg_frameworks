/*
 * Main.java
 *
 * Created on 29 May 2007, 16:40
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package compgraf;

import java.awt.Color;
import javax.swing.JFrame;

/**
 *
 * @author ale
 */
public class Main {
    
    /** Creates a new instance of Main */
    public Main() {
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        final int w = 320;
        final int h = 240;
        
        JFrame frame = new JFrame();
        frame.setBounds(0, 0, w, h);
        frame.setResizable(false);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        Canvas canvas = new Canvas(w, h);
        frame.add(canvas);
        
        frame.setVisible(true);        
        
        canvas.putpixel(0, 0, Color.RED);
        canvas.repaint();
        
        //canvas.clear();
        
    }
    
}
