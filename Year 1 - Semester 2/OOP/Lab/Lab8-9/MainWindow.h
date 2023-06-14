#pragma once

#include <QtWidgets/QApplication>
#include <QVBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QRadioButton>
#include <QButtonGroup>
#include <QMessageBox>
#include <QListWidget>
#include <qtablewidget>
#include <QLineEdit>

#include "ui_MainWindow.h"
#include "customexcpetion.h"
#include "controller.h"
#include "repository.h"
#include "domain.h"
#include <queue>
#include "utils.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#define DEFAULT_BASKET_CSV "CSVBasket.csv"
#define DEFAULT_BASKET_HTML "HTMLBasket.html"


class AdminWindow : public QWidget{
	Q_OBJECT;

private:
	ControllerAdministrator& controllerAdmin;

	QVBoxLayout* mainLayout;

	QVBoxLayout* titleLayout;
	QLabel* titleLabel;

	QHBoxLayout* coatsTableLayout;
	QTableWidget* coatsTableWidget;
	int columns;

	QVBoxLayout* lineEditsLayout;
	QHBoxLayout* sizeLineEditLayout, * colourLineEditLayout, * priceLineEditLayout, * quantityLineEditLayout, * photographLinkLineEditLayout;
	QLineEdit* sizeLineEdit, * colourLineEdit, * priceLineEdit, * quantityLineEdit, * photographLinkLineEdit;
	QLabel* sizeLineEditLabel, * colourLineEditLabel, * priceLineEditLabel, * quantityLineEditLabel, * photographLinkLineEditLabel;

	QHBoxLayout* buttonsLayout;
	QPushButton* addCoatButton;
	QPushButton* updateCoatButton;
	QPushButton* deleteCoatButton;
	
	void initResources();
	void initMainLayout();
	void initTitleLayout();
	void initLineEditsLayout();
	void initCoatTableLayout();
	void populateTable();
	void clearTable();
	void initButtonsLayout();
	void connectSignalsAndSlots();
	void addCoat();
	void updateCoat();
	void deleteCoat();
public:
	AdminWindow(ControllerAdministrator& _controllerAdmin, QWidget* parent = Q_NULLPTR);
	~AdminWindow();
};


class UserWindow : public QWidget{
	Q_OBJECT

private:
	ControllerUser& controllerUser;

	QVBoxLayout* mainLayout;

	QVBoxLayout* titleLayout;
	QLabel* titleLabel;

	QHBoxLayout* sizeButtonsGroupLayout;
	QButtonGroup* sizesGroup;
	QRadioButton * sizeSButton, * sizeMButton, * sizeLButton, * sizeXLButton, * sizeAllButton;
	
	QHBoxLayout* startOpenButtonsLayout;
	QPushButton* startPresentationCatalagoueButton, * openBasketFileButton;

	QHBoxLayout* tablesLayout;
	QTableWidget* currentCoat, * basketTable;
	QVBoxLayout* basketTableLayout;
	QLabel* basketPriceLabel;
	QVBoxLayout* currentCoatLayout;
	QHBoxLayout* navigationButtonsLayout;
	QPushButton * addCoatToBasketButton, * nextCoatButton, * displayCoatButton;

	std::queue<TrenchCoat> coats;

	void initTitleLayout();
	void initSizeButtonsGroupLayout();
	void initStartOpenButtonsLayout();
	void initTablesLayout();
	void initCurrentCoatLayout();
	void initBasketTableLayout();
	void initMainLayout();

	void populateBasketTable();
	void clearBasketTable();
	void populateCurrentCoat();
	void clearCurrentCoat();
	
	void connectSignalsAndSlots();
public:
	UserWindow(ControllerUser& _controllerUser, QWidget* parent = Q_NULLPTR);
	~UserWindow();
};


class MainWindow : public QWidget{
	Q_OBJECT

private:
	ControllerAdministrator& controllerAdmin;
	ControllerUser& controllerUser;

	BasketCSV* basketCSV;
	BasketHTML* basketHTML;
	
	AdminWindow* adminWindow;
	UserWindow* userWindow;

	QVBoxLayout* mainLayout;

	QVBoxLayout* welcomeMessageLayout;
	QLabel* welcomeMessageLabel;

	QVBoxLayout* launchLayout;
	QPushButton* launchButton;

	QHBoxLayout* optionsLayout;

	QVBoxLayout* basketModeLayout;
	QLabel* basketTitleMode;
	QButtonGroup* basketModeButtonGroup;
	QRadioButton* basketCSVButton;
	QRadioButton* basketHTMLButton;

	QVBoxLayout* modeLayout;
	QLabel* modeTitle;
	QButtonGroup* modeButtonGroup;
	QRadioButton* modeAdminButton;
	QRadioButton* modeUserButton;

	void initResources();
	void initMainLayout();
	void initWelcomeMessageLayout();
	void initLaunchLayout();
	void initBasketLayout();
	void initModeLayout();
	void initOptionsLayout();

	void connectSignalsAndSlots();
	void showLaunch();

public:
	MainWindow(ControllerAdministrator& _controllerAdmin, ControllerUser& _controllerUser, QWidget* parent = Q_NULLPTR);
	~MainWindow();
};