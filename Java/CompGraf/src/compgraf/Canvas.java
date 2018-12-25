/*
 * Canvas.java
 */

package compgraf;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import javax.swing.JPanel;

/**
 * @brief Un Canvas es un panel que puede incrustarse en un JFrame.
 * 
 * Ejemplo de uso:
 *
 *  public static void main(String[] args) {
 *       final int w = 320;
 *       final int h = 240;
 *       
 *       //Crear un JFrame para contener el Canvas:
 *       JFrame frame = new JFrame();
 *       frame.setBounds(0, 0, w, h);
 *       frame.setResizable(false);
 *       frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
 *       
 *       //Crear el Canvas:
 *       Canvas canvas = new Canvas(w, h);
 *       frame.add(canvas);
 *       
 *       frame.setVisible(true);        
 *       
 *       canvas.putpixel(0, 0, Color.RED);
 *       canvas.repaint();
 *
 */
public class Canvas extends JPanel
{
    
    private int w, h;
    private BufferedImage image;
    
    /** 
     *  Crear un nuevo canvas de w*h pixels. 
     *  @param w Ancho del canvas.
     *  @param h Alto del canvas.
     */
    public Canvas(int w, int h)
    {
        this.w = w;
        this.h = h;        
        this.setSize(w, h);
        image = new BufferedImage(w, h, BufferedImage.TYPE_INT_RGB);
        this.clear();
    }
    
    /**
     *  Pintar el pixel (x,y) del color c. (0,0) se encuentra en el centro del canvas.
     *  @param x absisa del pixel a pintar.
     *  @param y ordenada del pixel a pintar.
     *  @param c Color.
     **/
    public void putpixel(int x, int y, Color c)
    {
        int newx = x + w/2;
        int newy = -y + h/2;
        image.setRGB(newx, newy, c.getRGB());
    }
    
    /**
     *  Resetear el canvas a negro.
     **/
    public void clear()
    {
        image = new BufferedImage(w, h, BufferedImage.TYPE_INT_RGB);        
    }
    
    /**
     *  Actualizar el panel.
     **/
    public void paint(Graphics g)
    {
        g.drawImage(image, 0, 0, w, h, null);
    }
    
}
