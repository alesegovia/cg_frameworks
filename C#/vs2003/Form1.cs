using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;

using CompGraf;

namespace CompGraf2006
{
	/// <summary>
	/// Summary description for Form1.
	/// </summary>
	public class Form1 : System.Windows.Forms.Form
	{

		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.Container components = null;

		/// <summary>
		/// Canvas
		/// </summary>
		private Canvas canvas;

		public Form1()
		{
			//
			// Required for Windows Form Designer support
			//
			InitializeComponent();
			
			//Definir posicion y tamano:
			this.SetBounds(0,0,640,480);
			
			//Crear un nuevo canvas, agregarlo a este componente 
			//y hacerlo visible:
			canvas = new Canvas(640,480);
			this.Controls.Add(canvas);
			canvas.Visible = true;
			

			canvas.putpixel(0,0,Color.Red);
			canvas.putpixel(0,1,Color.Red);
			canvas.putpixel(0,-1,Color.Red);
			canvas.putpixel(1,0,Color.Red);
			canvas.putpixel(-1,0,Color.Red);
			
		}

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		protected override void Dispose( bool disposing )
		{
			if( disposing )
			{
				if (components != null) 
				{
					components.Dispose();
				}
			}
			base.Dispose( disposing );
		}

		#region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			// 
			// Form1
			// 
			this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
			this.ClientSize = new System.Drawing.Size(464, 334);
			this.Name = "Form1";
			this.Text = "Form1";

		}
		#endregion

		/// <summary>
		/// The main entry point for the application.
		/// </summary>
		[STAThread]
		static void Main() 
		{
			Application.Run(new Form1());
		}
	}
}
