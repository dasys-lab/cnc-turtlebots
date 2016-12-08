#ifndef NEWWORLDDIALOG_H
#define NEWWORLDDIALOG_H

#include <QtGui>
#include <QWidget>
#include <QDialog>
#include <rqt_gui_cpp/plugin.h>

#include <ui_newworlddialog.h>

using namespace std;
namespace wumpus_simulator
{
	class WumpusSimulator;
	class NewWorldDialog : public QDialog
	{
	Q_OBJECT

	public:
		NewWorldDialog(QWidget * parent, WumpusSimulator* sim);

	private slots:

		void randomButton();
		void buttonBox_acc();
		void buttonBox_rej();

	private:
		Ui::NewWorldDialog NewWorldView;
		WumpusSimulator* sim;

	};
}
#endif // NEWWORLDDIALOG_H
