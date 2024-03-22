using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
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
    /// Interaction logic for LibraryScreen.xaml
    /// </summary>
    public partial class LibraryScreen : Window
    {
        public ObservableCollection<UserControl1> book { get; set; }


        public LibraryScreen()
        {
            InitializeComponent();

            book = new ObservableCollection<UserControl1>
            {

            new UserControl1
                    {
                        Image = "/Images/Book.jpg",
                        Title = "Title 1",
                        Author = "Author 1",

                    },
                new UserControl1
                    {
                         Image = "/Images/Book.jpg",
                        Title = "Title 2",
                        Author = "Author 2",

                    },

                new UserControl1
                    {
                       Image = "/Images/Book.jpg",
                        Title = "Title 3",
                        Author = "Auhtor 3",

                    },
                new UserControl1
                    {
                        Image = "/Images/Book.jpg",
                        Title = "Title 4",
                        Author = "Auhtor 4",

                    },
                new UserControl1
                    {
                        Image = "/Images/Book.jpg",
                        Title = "Title 5",
                        Author = "Auhtor 5",

                    }
            };


           listBox.DataContext = book;
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {

        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {

        }

        private void TextBox_TextChanged(object sender, TextChangedEventArgs e)
        {

        }

        private void listBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (listBox.SelectedItem != null)
            {
                double windowWidth = this.ActualWidth;
                double windowHeight = this.ActualHeight;

                UserControl1 selectedBook = (UserControl1)listBox.SelectedItem;


                BookInfo bookScreen = new BookInfo(selectedBook.Image, selectedBook.Title, selectedBook.Author);


                bookScreen.Width = windowWidth;
                bookScreen.Height = windowHeight;


                bookScreen.Show();
                this.Close();
            }
        }
    }
}
