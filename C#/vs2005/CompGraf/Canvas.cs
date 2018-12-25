using System;
using System.Windows.Forms;
using System.Drawing;
using System.Media;
using System.Drawing.Imaging;

namespace CompGraf
{
	/// <summary>
	/// Implementa un Canvas como una extension a Panel, mas inteligente.
	/// </summary>
	public class Canvas : Panel
	{
		//Almacenamiento del tamano
		private int width;
        private int height;

		//Imagen interna donde dibujamos
		Bitmap bmp;

		/// <summary>
		/// Crea un nuevo canvas del tamano especificado.
		/// </summary>
		/// <param name="width">Largo</param>
		/// <param name="height">Ancho</param>
		public Canvas(int width, int height)
		{
			//Almacenar largo
			this.width = width;
			
			//Almacenar ancho
			this.height = height;			
			
			//Especificar tamano del Panel - Importante!!
			this.SetBounds(0,0,width,height);
			
			//Crear nuevo bitmap
			bmp = new Bitmap(width,height);
            
            //Pintar el bitmap de negro, escribiendo directo en su memoria (rapido)
            this.BackColor = Color.Black;
		}

        /// <summary>
        /// Dibuja un pixel sobre el canvas, donde (0,0) corresponde al
        /// centro de la imagen.
        /// </summary>
        /// <param name="x">Abscisa del punto</param>
        /// <param name="y">Ordenada del punto</param>
        /// <param name="c">Color a pintar</param>
        public void putpixel(int x, int y, Color c)
		{
			//Cambio de Coordenadas
			int x1 = x + width/2;
			int y1 = height/2 - y;
			
			//Putpixel sobre el bitmap
			bmp.SetPixel(x1,y1,c);
		}

		/// <summary>
		/// Evento invocado cuando se solicita que el canvas se repinte
		/// </summary>
		/// <param name="e">PaintEvent Arguments</param>
		protected override void OnPaint(PaintEventArgs e)
		{
			//Dibujar nuestra base (padre)
			base.OnPaint (e);
			//Crear un nuevo objeto graphics para pintar el bitmap sobre 
			//nosotros mismos
			Graphics g = this.CreateGraphics();
			g.DrawImage(bmp,0,0,width,height);
		}

        /// <summary>
        /// Reestablecer el canvas a negro.
        /// </summary>
		public void Clear()
		{
			bmp = new Bitmap(width,height);
		}

        private void InitializeComponent()
        {
            this.SuspendLayout();
            this.ResumeLayout(false);
        }


	}
}
