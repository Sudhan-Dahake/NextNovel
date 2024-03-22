using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace NextNovel
{
    /// <summary>
    /// Interaction logic for BookInfo.xaml
    /// </summary>
    public partial class BookInfo : Window
    {
        public string BookTitle { get; set; }
        public string Author { get; set; }
        public string ImagePath { get; set; }

        public BookInfo(string image, string title, string author)
        {
            InitializeComponent();

            ImagePath = image;
            BookTitle = title;
            Author = author;

            DataContext = this;
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {

        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {

        }

        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            double windowWidth = this.ActualWidth;
            double windowHeight = this.ActualHeight;

            LibraryScreen library = new LibraryScreen();


            library.Width = windowWidth;
            library.Height = windowHeight;


            library.Show();
            this.Close();
        }

        private void TextBox_TextChanged(object sender, TextChangedEventArgs e)
        {

        }
    }
}
