#include "MainWindow.h"

void MainWindow::initMainLayout()
{	
	this->mainLayout = new QVBoxLayout(this);
	this->initWelcomeMessageLayout();
	this->mainLayout->addStretch(1);
	this->initOptionsLayout();
	this->mainLayout->addStretch(1);
	this->initLaunchLayout();
}


void MainWindow::initWelcomeMessageLayout()
{
	this->welcomeMessageLayout = new QVBoxLayout;
	
	this->welcomeMessageLabel = new QLabel;

	this->welcomeMessageLabel->setText("<p style='text-align: center;'>Welcome!</p>");
	QFont welcomeLabel = this->welcomeMessageLabel->font();
	welcomeLabel.setPointSize(14);

	this->welcomeMessageLabel->setFont(welcomeLabel);
	this->welcomeMessageLayout->addWidget(this->welcomeMessageLabel);
	this->mainLayout->addLayout(this->welcomeMessageLayout);
}

void MainWindow::initOptionsLayout()
{
	this->optionsLayout = new QHBoxLayout;

	this->optionsLayout->addStretch(1);
	this->initBasketLayout();
	this->optionsLayout->addStretch(1);
	this->initModeLayout();
	this->optionsLayout->addStretch(1);

	this->mainLayout->addLayout(this->optionsLayout);
}


void MainWindow::initBasketLayout()
{
	//init group BASKET options and suttons
	this->basketModeLayout = new QVBoxLayout;

	this->basketTitleMode = new QLabel("Basket type:");
	this->basketModeLayout->addWidget(this->basketTitleMode);

	this->basketModeButtonGroup = new QButtonGroup;
	
	this->basketHTMLButton = new QRadioButton("HTML");
	this->basketCSVButton = new QRadioButton("CSV");

	//init layout for the options of the basket (html or css)
	this->basketModeButtonGroup->addButton(this->basketHTMLButton);
	this->basketModeButtonGroup->addButton(this->basketCSVButton);
	
	this->basketModeLayout->addWidget(this->basketHTMLButton);
	this->basketModeLayout->addWidget(this->basketCSVButton);
	
	this->optionsLayout->addLayout(this->basketModeLayout);
}

void MainWindow::initModeLayout()
{
	//init group USER MODE options and buttons
	this->modeLayout = new QVBoxLayout;

	this->modeTitle = new QLabel("Mode:");
	this->modeLayout->addWidget(this->modeTitle);

	this->modeButtonGroup = new QButtonGroup;

	this->modeAdminButton = new QRadioButton("Admin");
	this->modeUserButton = new QRadioButton("User");

	//init layout for the options of the user mode (admin or user)
	this->modeButtonGroup->addButton(this->modeAdminButton);
	this->modeButtonGroup->addButton(this->modeUserButton);
	
	this->modeLayout->addWidget(this->modeAdminButton);
	this->modeLayout->addWidget(this->modeUserButton);
	
	this->optionsLayout->addLayout(this->modeLayout);
}


void MainWindow::initLaunchLayout()
{
	this->launchLayout = new QVBoxLayout;

	this->launchButton = new QPushButton("Launch");

	this->launchLayout->addWidget(this->launchButton);

	this->mainLayout->addLayout(launchLayout);
}

void MainWindow::connectSignalsAndSlots()
{
	QObject::connect(this->launchButton, &QPushButton::clicked, this, &MainWindow::showLaunch);
}

void MainWindow::showLaunch()
{
	try{
		if (this->modeAdminButton->isChecked()){
			this->adminWindow->show();
		}
		else if (this->modeUserButton->isChecked()){
			if (this->basketCSVButton->isChecked()){
				controllerUser.setBasket(basketCSV);
			}
			else if (this->basketHTMLButton->isChecked()){
				controllerUser.setBasket(basketHTML);
			}
			else{
				throw std::exception("A basket mode must be selected!");
			}
			this->userWindow->show();
		}
		else{
			throw std::exception("Select options!");
		}
	}
	catch (std::exception& e){
		QMessageBox::critical(this, "Exception", e.what());
	}
}

void MainWindow::initResources()
{
	this->basketCSV = new BasketCSV(DEFAULT_BASKET_CSV);
	this->basketHTML = new BasketHTML(DEFAULT_BASKET_HTML);
	
	this->controllerUser.setBasket(this->basketHTML); // set by default HTML Basket

	this->adminWindow = new AdminWindow(controllerAdmin);  this->adminWindow->setWindowTitle("Admin mode");
	this->userWindow = new UserWindow(controllerUser); this->userWindow->setWindowTitle("User mode");
}

MainWindow::MainWindow(ControllerAdministrator& _controllerAdmin, ControllerUser& _controllerUser, QWidget* parent) :
	QWidget{parent}, controllerAdmin{_controllerAdmin}, controllerUser{_controllerUser}
{	
	this->initResources();
	this->initMainLayout();
	this->connectSignalsAndSlots();
}

MainWindow::~MainWindow()
{
	delete this->basketHTMLButton; this->basketHTMLButton = nullptr;
	delete this->basketCSVButton; this->basketCSVButton = nullptr;
	delete this->basketModeButtonGroup; this->basketModeButtonGroup = nullptr;
	delete this->basketTitleMode; this->basketTitleMode = nullptr;
	delete this->basketModeLayout; this->basketModeLayout = nullptr;

	delete this->modeUserButton; this->modeUserButton = nullptr;
	delete this->modeAdminButton; this->modeAdminButton = nullptr;
	delete this->modeButtonGroup; this->modeButtonGroup = nullptr;
	delete this->modeTitle; this->modeTitle = nullptr;
	delete this->modeLayout; this->modeLayout = nullptr;

	delete this->launchButton; this->launchButton = nullptr;
	delete this->launchLayout; this->launchLayout = nullptr;
	
	delete this->welcomeMessageLabel; this->welcomeMessageLabel = nullptr;
	delete this->welcomeMessageLayout; this->welcomeMessageLayout = nullptr;

	delete this->optionsLayout; this->optionsLayout = nullptr;
	delete this->mainLayout; this->mainLayout = nullptr;

	delete this->basketCSV; this->basketCSV = nullptr;
	delete this->basketHTML; this->basketHTML = nullptr;

	delete this->adminWindow; this->adminWindow = nullptr;
	delete this->userWindow; this->userWindow = nullptr;
}

void AdminWindow::initResources()
{
}

void AdminWindow::initMainLayout()
{
	this->mainLayout = new QVBoxLayout(this);
	this->setLayout(this->mainLayout);

	this->mainLayout->addStretch(1);
	this->initTitleLayout();
	this->mainLayout->addStretch(1);
	this->initCoatTableLayout();
	this->mainLayout->addStretch(1);
	this->initButtonsLayout();
	this->mainLayout->addStretch(1);
}

void AdminWindow::initTitleLayout()
{
	this->titleLayout = new QVBoxLayout;
	this->titleLabel = new QLabel;
	this->titleLabel->setText("<p style='text-align: center;'>Admin mode</p>");

	QFont titleFont = this->titleLabel->font();
	titleFont.setPointSize(14);

	this->titleLabel->setFont(titleFont);
	this->titleLayout->addWidget(this->titleLabel);

	this->mainLayout->addLayout(this->titleLayout);
}

void AdminWindow::initLineEditsLayout()
{
	this->lineEditsLayout = new QVBoxLayout(this);

	this->sizeLineEditLayout = new QHBoxLayout();
	this->colourLineEditLayout = new QHBoxLayout();
	this->priceLineEditLayout = new QHBoxLayout();
	this->quantityLineEditLayout = new QHBoxLayout();
	this->photographLinkLineEditLayout = new QHBoxLayout();

	this->sizeLineEdit = new QLineEdit; this->sizeLineEditLabel = new QLabel("size");
	this->colourLineEdit = new QLineEdit; this->colourLineEditLabel = new QLabel("colour");
	this->priceLineEdit = new QLineEdit; this->priceLineEditLabel = new QLabel("price");
	this->quantityLineEdit = new QLineEdit; this->quantityLineEditLabel = new QLabel("quantity");
	this->photographLinkLineEdit = new QLineEdit; this->photographLinkLineEditLabel = new QLabel("link");

	this->sizeLineEditLayout->addWidget(this->sizeLineEditLabel);
	this->sizeLineEditLayout->addWidget(this->sizeLineEdit);

	this->colourLineEditLayout->addWidget(this->colourLineEditLabel);
	this->colourLineEditLayout->addWidget(this->colourLineEdit);

	this->priceLineEditLayout->addWidget(this->priceLineEditLabel);
	this->priceLineEditLayout->addWidget(this->priceLineEdit);

	this->quantityLineEditLayout->addWidget(this->quantityLineEditLabel);
	this->quantityLineEditLayout->addWidget(this->quantityLineEdit);

	this->photographLinkLineEditLayout->addWidget(this->photographLinkLineEditLabel);
	this->photographLinkLineEditLayout->addWidget(this->photographLinkLineEdit);

	this->lineEditsLayout->addLayout(this->sizeLineEditLayout);
	this->lineEditsLayout->addLayout(this->colourLineEditLayout);
	this->lineEditsLayout->addLayout(this->priceLineEditLayout);
	this->lineEditsLayout->addLayout(this->quantityLineEditLayout);
	this->lineEditsLayout->addLayout(this->photographLinkLineEditLayout);

	this->coatsTableLayout->addLayout(this->lineEditsLayout);
}

void AdminWindow::initCoatTableLayout()
{
	this->coatsTableLayout = new QHBoxLayout;

	//Create table
	this->columns = 5;
	this->coatsTableWidget = new QTableWidget;
	
	//add table to coatsTableLayout
	this->coatsTableLayout->addWidget(this->coatsTableWidget);

	//populate table
	this->populateTable();

	this->initLineEditsLayout();

	this->mainLayout->addLayout(this->coatsTableLayout);
	
}

void AdminWindow::populateTable()
{
	this->clearTable();
	std::vector<TrenchCoat>& v = this->controllerAdmin.get();
	this->coatsTableWidget->setRowCount(v.size());
	this->coatsTableWidget->setColumnCount(this->columns);

	this->coatsTableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Size"));
	this->coatsTableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Colour"));
	this->coatsTableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Price"));
	this->coatsTableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Quantity"));
	this->coatsTableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Photograph Link"));

	int currRow = 0;
	std::for_each(v.begin(), v.end(), [&](TrenchCoat& tc){
		QTableWidgetItem* col1, * col2, * col3, * col4, * col5;
		col1 = new QTableWidgetItem(QString::fromStdString(tc.getSize()));
		col2 = new QTableWidgetItem(QString::fromStdString(tc.getColor()));
		col3 = new QTableWidgetItem(QString::fromStdString(std::to_string(tc.getPrice())));
		col4 = new QTableWidgetItem(QString::fromStdString(std::to_string(tc.getQuantity())));
		col5 = new QTableWidgetItem(QString::fromStdString(tc.getPhotographLink()));
		this->coatsTableWidget->setItem(currRow, 0, col1);
		this->coatsTableWidget->setItem(currRow, 1, col2);
		this->coatsTableWidget->setItem(currRow, 2, col3);
		this->coatsTableWidget->setItem(currRow, 3, col4);
		this->coatsTableWidget->setItem(currRow, 4, col5);
		currRow++;
		});
}

void AdminWindow::clearTable()
{
	int rowCout = this->coatsTableWidget->rowCount();
	int columnCount = this->coatsTableWidget->columnCount();

	for (int col = 0; col < columnCount; col++){
		this->coatsTableWidget->horizontalHeaderItem(col);
	}

	for (int row = 0; row < rowCout; row++){
		for (int col = 0; col < columnCount; col++){
			QTableWidgetItem* item = this->coatsTableWidget->item(row, col);
			delete item;
		}
	}
}

void AdminWindow::initButtonsLayout()
{
	this->buttonsLayout = new QHBoxLayout;
	this->mainLayout->addLayout(this->buttonsLayout);
	
	this->addCoatButton = new QPushButton("Add");
	this->buttonsLayout->addWidget(this->addCoatButton);

	this->updateCoatButton = new QPushButton("Update");
	this->buttonsLayout->addWidget(this->updateCoatButton);

	this->deleteCoatButton = new QPushButton("Delete");
	this->buttonsLayout->addWidget(this->deleteCoatButton);
}

void AdminWindow::connectSignalsAndSlots()
{
	QObject::connect(this->coatsTableWidget, &QTableWidget::itemClicked, this, [&](QTableWidgetItem* item){
		int row = item->row();
		if (0 <= row && row <= this->coatsTableWidget->rowCount()){
			this->sizeLineEdit->clear();
			this->colourLineEdit->clear();
			this->priceLineEdit->clear();
			this->quantityLineEdit->clear();
			this->photographLinkLineEdit->clear();

			QString size, colour, price, quantity, photographLink;

			size = this->coatsTableWidget->item(row, 0)->text();
			colour = this->coatsTableWidget->item(row, 1)->text();
			price = this->coatsTableWidget->item(row, 2)->text();
			quantity = this->coatsTableWidget->item(row, 3)->text();
			photographLink = this->coatsTableWidget->item(row, 4)->text();

			this->sizeLineEdit->setText(size);
			this->colourLineEdit->setText(colour);
			this->priceLineEdit->setText(price);
			this->quantityLineEdit->setText(quantity);
			this->photographLinkLineEdit->setText(photographLink);
		}
		});
	QObject::connect(this->addCoatButton, &QPushButton::clicked, this, &AdminWindow::addCoat);
	QObject::connect(this->updateCoatButton, &QPushButton::clicked, this, &AdminWindow::updateCoat);
	QObject::connect(this->deleteCoatButton, &QPushButton::clicked, this, &AdminWindow::deleteCoat);
}

void AdminWindow::addCoat()
{
	std::string errors;

	std::string size, colour, _price, _quantity, photographLink;
	int price, quantity;

	try{
		size = this->sizeLineEdit->text().toStdString();
		Utils::formatSentence(size);
	}
	catch (std::exception& e){
		errors = errors + std::string(e.what()) + "\n";
	}

	try{
		colour = this->colourLineEdit->text().toStdString();
		Utils::formatSentence(colour);
	}
	catch (std::exception& e){
		errors = errors + std::string(e.what()) + "\n";
	}

	try{
		_price = this->priceLineEdit->text().toStdString();
		Utils::formatSentence(_price);
		price = std::stoi(_price);
	}
	catch (std::exception& e){
		errors = errors + "Price conversion to int failure!" + "\n";
	}

	try{
		_quantity = this->quantityLineEdit->text().toStdString();
		Utils::formatSentence(_quantity);
		quantity = std::stoi(_quantity);
	}
	catch (std::exception& e){
		errors = errors + "Quantity conversion to int failure!" + "\n";
	}

	try{
		photographLink = this->photographLinkLineEdit->text().toStdString();
		Utils::formatSentence(photographLink);
	}
	catch (std::exception& e){
		errors = errors + std::string(e.what()) + "\n";
	}

	if (!errors.empty()){
		QMessageBox::critical(this, "Exception", QString::fromStdString(errors));
		return;
	}
	
	//validation
	if (!TrenchCoatValidator::isSizeValid(size)){
		errors += "Size must be S, M, L or XL!\n";
	}

	if (!TrenchCoatValidator::isColourValid(colour)){
		errors += "Color not valid!\n";
	}

	if (!TrenchCoatValidator::isPriceValid(price)){
		errors += "Price must be a positive integer!\n";
	}

	if (!TrenchCoatValidator::isQuantityValid(price)){
		errors += "Quantity must be a positive integer!\n";
	}

	if (!TrenchCoatValidator::isPhotographLinkValid(photographLink)){
		errors += "The photograph link not valid!\n";
	}

	if (!errors.empty()){
		QMessageBox::critical(this, "Exception", QString::fromStdString(errors));
		return;
	}

	try{
		TrenchCoat tc{size, colour, price, quantity, photographLink};
		this->controllerAdmin.add(tc);
		this->populateTable();
	}
	catch (std::exception& e){
		QMessageBox::critical(this, "Exception", QString::fromStdString(std::string(e.what())));
	}

}

void AdminWindow::updateCoat()
{
	try{
		int row = this->coatsTableWidget->currentItem()->row();
		std::string size, colour, _price, _quantity, photographLink;
		int price, quantity;

		size = this->coatsTableWidget->item(row, 0)->text().toStdString(); Utils::formatSentence(size);
		colour = this->coatsTableWidget->item(row, 1)->text().toStdString(); Utils::formatSentence(colour);
		_price = this->coatsTableWidget->item(row, 2)->text().toStdString(); Utils::formatSentence(_price); price = std::stoi(_price);
		_quantity = this->coatsTableWidget->item(row, 3)->text().toStdString(); Utils::formatSentence(_quantity); quantity = std::stoi(_quantity);
		photographLink = this->coatsTableWidget->item(row, 4)->text().toStdString(); Utils::formatSentence(photographLink);
		
		TrenchCoat tc{size, colour, price, quantity, photographLink};

		int newPrice, newQuantity;
		newPrice = std::stoi(this->priceLineEdit->text().toStdString());
		newQuantity = std::stoi(this->quantityLineEdit->text().toStdString());

		this->controllerAdmin.update(tc, newPrice, newQuantity);
		this->populateTable();
	}
	catch (RepositoryException& e){
		QMessageBox::critical(this, "Exception", QString::fromStdString(std::string(e.what())));
	}
	catch (std::exception& e){
		QMessageBox::critical(this, "Exception", QString::fromStdString(std::string(e.what())));
	}
}

void AdminWindow::deleteCoat()
{
	std::string errors;

	std::string size, colour, _price, _quantity, photographLink;
	int price, quantity;

	try{
		size = this->sizeLineEdit->text().toStdString();
		Utils::formatSentence(size);
	}
	catch (std::exception& e){
		errors = errors + std::string(e.what()) + "\n";
	}

	try{
		colour = this->colourLineEdit->text().toStdString();
		Utils::formatSentence(colour);
	}
	catch (std::exception& e){
		errors = errors + std::string(e.what()) + "\n";
	}

	try{
		_price = this->priceLineEdit->text().toStdString();
		Utils::formatSentence(_price);
		price = std::stoi(_price);
	}
	catch (std::exception& e){
		errors = errors + "Price conversion to int failure!" + "\n";
	}

	try{
		_quantity = this->quantityLineEdit->text().toStdString();
		Utils::formatSentence(_quantity);
		quantity = std::stoi(_quantity);
	}
	catch (std::exception& e){
		errors = errors + "Quantity conversion to int failure!" + "\n";
	}

	try{
		photographLink = this->photographLinkLineEdit->text().toStdString();
		Utils::formatSentence(photographLink);
	}
	catch (std::exception& e){
		errors = errors + std::string(e.what()) + "\n";
	}

	if (!errors.empty()){
		QMessageBox::critical(this, "Exception", QString::fromStdString(errors));
		return;
	}

	//validation
	if (!TrenchCoatValidator::isSizeValid(size)){
		errors += "Size must be S, M, L or XL!\n";
	}

	if (!TrenchCoatValidator::isColourValid(colour)){
		errors += "Color not valid!\n";
	}

	if (!TrenchCoatValidator::isPriceValid(price)){
		errors += "Price must be a positive integer!\n";
	}

	if (!TrenchCoatValidator::isQuantityValid(price)){
		errors += "Quantity must be a positive integer!\n";
	}

	if (!TrenchCoatValidator::isPhotographLinkValid(photographLink)){
		errors += "The photograph link not valid!\n";
	}

	if (!errors.empty()){
		QMessageBox::critical(this, "Exception", QString::fromStdString(errors));
		return;
	}

	try{
		TrenchCoat tc{size, colour, price, quantity, photographLink};
		this->controllerAdmin.remove(tc, tc.getQuantity());
		this->populateTable();
	}
	catch (RepositoryException& e){
		QMessageBox::critical(this, "Exception", QString::fromStdString(std::string(e.what())));
	}
	catch (std::exception& e){
		QMessageBox::critical(this, "Exception", QString::fromStdString(std::string(e.what())));
	}
}

AdminWindow::AdminWindow(ControllerAdministrator& _controllerAdmin, QWidget* parent) : controllerAdmin{_controllerAdmin},
	QWidget{parent}
{
	this->initResources();
	this->initMainLayout();
	this->connectSignalsAndSlots();
}

AdminWindow::~AdminWindow()
{
	//title layout
	delete this->titleLabel; this->titleLabel = nullptr;
	delete this->titleLayout; this->titleLayout = nullptr;

	//line edits layout
	delete this->sizeLineEditLabel; this->sizeLineEditLabel = nullptr;
	delete this->colourLineEditLabel; this->colourLineEditLabel = nullptr;
	delete this->priceLineEditLabel; this->priceLineEditLabel = nullptr;
	delete this->quantityLineEditLabel; this->quantityLineEditLabel = nullptr;
	delete this->photographLinkLineEditLabel; this->photographLinkLineEditLabel = nullptr;

	delete this->sizeLineEdit; this->sizeLineEdit = nullptr;
	delete this->colourLineEdit; this->colourLineEdit = nullptr;
	delete this->priceLineEdit; this->priceLineEdit = nullptr;
	delete this->quantityLineEdit; this->quantityLineEdit = nullptr;
	delete this->photographLinkLineEdit; this->photographLinkLineEdit = nullptr;

	delete this->sizeLineEditLayout; this->sizeLineEditLayout = nullptr;
	delete this->colourLineEditLayout; this->colourLineEditLayout = nullptr;
	delete this->priceLineEditLayout; this->priceLineEditLayout = nullptr;
	delete this->quantityLineEditLayout; this->quantityLineEditLayout = nullptr;
	delete this->photographLinkLineEditLayout; this->photographLinkLineEditLayout = nullptr;

	delete this->lineEditsLayout; this->lineEditsLayout = nullptr;
	
	//coats table layout
	delete this->coatsTableWidget; this->coatsTableWidget = nullptr;
	delete this->coatsTableLayout; this->coatsTableLayout = nullptr;

	//delete buttons
	delete this->addCoatButton; this->addCoatButton = nullptr;
	delete this->updateCoatButton; this->updateCoatButton = nullptr;
	delete this->deleteCoatButton; this->deleteCoatButton = nullptr;

	delete this->buttonsLayout; this->buttonsLayout = nullptr;

	//main layout
	delete this->mainLayout; this->mainLayout = nullptr;
}


void UserWindow::initTitleLayout()
{
	this->titleLayout = new QVBoxLayout;

	this->mainLayout->addLayout(this->titleLayout);

	this->titleLabel = new QLabel;
	
	this->titleLayout->addWidget(this->titleLabel);

	this->titleLabel->setText("<p style='text-align: center'>User mode</p>");

	QFont titleFont = this->titleLabel->font();
	titleFont.setPointSize(14);
	this->titleLabel->setFont(titleFont);
}

void UserWindow::initSizeButtonsGroupLayout()
{
	this->sizeButtonsGroupLayout = new QHBoxLayout;

	this->sizesGroup = new QButtonGroup;

	this->sizeSButton = new QRadioButton("S");
	this->sizesGroup->addButton(this->sizeSButton);
	this->sizeButtonsGroupLayout->addWidget(this->sizeSButton);

	this->sizeMButton = new QRadioButton("M");
	this->sizesGroup->addButton(this->sizeMButton);
	this->sizeButtonsGroupLayout->addWidget(this->sizeMButton);

	this->sizeLButton = new QRadioButton("L");
	this->sizesGroup->addButton(this->sizeLButton);
	this->sizeButtonsGroupLayout->addWidget(this->sizeLButton);

	this->sizeXLButton = new QRadioButton("XL");
	this->sizesGroup->addButton(this->sizeXLButton);
	this->sizeButtonsGroupLayout->addWidget(this->sizeXLButton);

	this->sizeAllButton = new QRadioButton("All");
	this->sizesGroup->addButton(this->sizeAllButton);
	this->sizeButtonsGroupLayout->addWidget(this->sizeAllButton);

	this->mainLayout->addLayout(this->sizeButtonsGroupLayout);
}

void UserWindow::initStartOpenButtonsLayout()
{
	this->startOpenButtonsLayout = new QHBoxLayout;
	
	this->mainLayout->addLayout(this->startOpenButtonsLayout);

	this->startPresentationCatalagoueButton = new QPushButton("Start Presentation");

	this->startOpenButtonsLayout->addWidget(this->startPresentationCatalagoueButton);

	this->openBasketFileButton = new QPushButton("Open basket file");

	this->startOpenButtonsLayout->addWidget(this->openBasketFileButton);
}

void UserWindow::initTablesLayout()
{
	this->tablesLayout = new QHBoxLayout;
	this->mainLayout->addLayout(this->tablesLayout);
	this->initCurrentCoatLayout();
	this->initBasketTableLayout();
}

void UserWindow::initCurrentCoatLayout()
{	
	this->currentCoatLayout = new QVBoxLayout;
	this->tablesLayout->addLayout(this->currentCoatLayout);

	this->basketTableLayout = new QVBoxLayout;
	this->tablesLayout->addLayout(this->basketTableLayout);

	this->navigationButtonsLayout = new QHBoxLayout;

	this->currentCoat = new QTableWidget;
	this->currentCoatLayout->addWidget(this->currentCoat);

	this->currentCoatLayout->addLayout(this->navigationButtonsLayout);

	this->addCoatToBasketButton = new QPushButton("Add to basket");
	this->navigationButtonsLayout->addWidget(this->addCoatToBasketButton);

	this->nextCoatButton = new QPushButton("Next coat");
	this->navigationButtonsLayout->addWidget(this->nextCoatButton);

	this->displayCoatButton = new QPushButton("Display coat");
	this->navigationButtonsLayout->addWidget(this->displayCoatButton);
	
}

void UserWindow::initBasketTableLayout()
{
	this->basketTable = new QTableWidget;
	this->tablesLayout->addWidget(this->basketTable);

	this->basketPriceLabel = new QLabel("Total: 0");
	this->tablesLayout->addWidget(this->basketPriceLabel);
}


void UserWindow::initMainLayout()
{
	this->mainLayout = new QVBoxLayout(this);

	this->initTitleLayout();

	this->initSizeButtonsGroupLayout();

	this->initStartOpenButtonsLayout();

	this->initTablesLayout();

	this->connectSignalsAndSlots();
}

void UserWindow::populateBasketTable()
{
	this->clearBasketTable();
	std::vector<TrenchCoat>& v = this->controllerUser.getBasket();

	int rows = v.size();
	int cols = 5;
	this->basketTable->setRowCount(rows);
	this->basketTable->setColumnCount(cols);

	this->basketTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Size"));
	this->basketTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Colour"));
	this->basketTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Price"));
	this->basketTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Quantity"));
	this->basketTable->setHorizontalHeaderItem(4, new QTableWidgetItem("Photograph Link"));

	int currRow = 0;
	std::for_each(v.begin(), v.end(), [&](TrenchCoat& tc){
		QTableWidgetItem* col1, * col2, * col3, * col4, * col5;
		col1 = new QTableWidgetItem(QString::fromStdString(tc.getSize()));
		col2 = new QTableWidgetItem(QString::fromStdString(tc.getColor()));
		col3 = new QTableWidgetItem(QString::fromStdString(std::to_string(tc.getPrice())));
		col4 = new QTableWidgetItem(QString::fromStdString(std::to_string(tc.getQuantity())));
		col5 = new QTableWidgetItem(QString::fromStdString(tc.getPhotographLink()));
		this->basketTable->setItem(currRow, 0, col1);
		this->basketTable->setItem(currRow, 1, col2);
		this->basketTable->setItem(currRow, 2, col3);
		this->basketTable->setItem(currRow, 3, col4);
		this->basketTable->setItem(currRow, 4, col5);
		currRow++;
		});

	this->basketPriceLabel->setText(QString::fromStdString("Total: " + std::to_string(this->controllerUser.getBasketTotal())));
}

void UserWindow::clearBasketTable()
{
	int rowCout = this->basketTable->rowCount();
	int columnCount = this->basketTable->columnCount();

	for (int col = 0; col < columnCount; col++){
		delete this->basketTable->horizontalHeaderItem(col);
	}

	for (int row = 0; row < rowCout; row++){
		for (int col = 0; col < columnCount; col++){
			QTableWidgetItem* item = this->basketTable->item(row, col);
			delete item;
		}
	}
	this->basketPriceLabel->setText(QString::fromStdString("Total: 0"));
}

void UserWindow::populateCurrentCoat()
{
	this->clearCurrentCoat();
	TrenchCoat tc = this->coats.front();
	int rows = 1;
	int cols = 5;
	this->currentCoat->setRowCount(1);
	this->currentCoat->setColumnCount(5);
	this->currentCoat->setHorizontalHeaderItem(0, new QTableWidgetItem("Size"));
	this->currentCoat->setHorizontalHeaderItem(1, new QTableWidgetItem("Colour"));
	this->currentCoat->setHorizontalHeaderItem(2, new QTableWidgetItem("Price"));
	this->currentCoat->setHorizontalHeaderItem(3, new QTableWidgetItem("Quantity"));
	this->currentCoat->setHorizontalHeaderItem(4, new QTableWidgetItem("Photograph Link"));

	QTableWidgetItem* col1, * col2, * col3, * col4, * col5;
	col1 = new QTableWidgetItem(QString::fromStdString(tc.getSize()));
	col2 = new QTableWidgetItem(QString::fromStdString(tc.getColor()));
	col3 = new QTableWidgetItem(QString::fromStdString(std::to_string(tc.getPrice())));
	col4 = new QTableWidgetItem(QString::fromStdString(std::to_string(tc.getQuantity())));
	col5 = new QTableWidgetItem(QString::fromStdString(tc.getPhotographLink()));
	this->currentCoat->setItem(0, 0, col1);
	this->currentCoat->setItem(0, 1, col2);
	this->currentCoat->setItem(0, 2, col3);
	this->currentCoat->setItem(0, 3, col4);
	this->currentCoat->setItem(0, 4, col5);

}

void UserWindow::clearCurrentCoat()
{
	int rowCout = this->currentCoat->rowCount();
	int columnCount = this->currentCoat->columnCount();

	for (int col = 0; col < columnCount; col++){
		delete this->currentCoat->horizontalHeaderItem(col);
	}

	for (int col = 0; col < columnCount; col++){
		QTableWidgetItem* item = this->currentCoat->item(0, col);
		delete item;
	}
}

void UserWindow::connectSignalsAndSlots()
{
	QObject::connect(this->startPresentationCatalagoueButton, &QPushButton::clicked, this, [&](){
		std::string size = "";
		if (this->sizeSButton->isChecked()){
			size = "s";
		}
		else if (this->sizeMButton->isChecked()){
			size = "m";
		}
		else if (this->sizeLButton->isChecked()){
			size = "l";
		}
		else if (this->sizeXLButton->isChecked()){
			size = "xl";
		}
		else if (this->sizeAllButton->isChecked()){
			size = "";
		}
		else{
			QMessageBox::critical(this, "Exception", "A size must be checked!");
			return;
		}
		std::vector<TrenchCoat> v = this->controllerUser.getRepo(size);
		std::queue<TrenchCoat> q;
		std::for_each(v.begin(), v.end(), [&](TrenchCoat& tc){
			q.push(tc);
			});
		this->coats = q;
		this->populateCurrentCoat();
		});
	QObject::connect(this->openBasketFileButton, &QPushButton::clicked, this, [&](){
		std::string cmd = "start " + this->controllerUser.getFileName();
		system(cmd.c_str());
		});
	QObject::connect(this->addCoatToBasketButton, &QPushButton::clicked, this, [&](){
		if (this->coats.size() > 0){
			TrenchCoat& tc = this->coats.front();
			this->controllerUser.addToBasket(tc);
			this->populateBasketTable();
		}
		});
	QObject::connect(this->nextCoatButton, &QPushButton::clicked, this, [&](){
		if (this->coats.size() > 0){
			TrenchCoat tc = this->coats.front();
			this->coats.pop();
			this->coats.push(tc);
			this->populateCurrentCoat();
		}
		});
	QObject::connect(this->displayCoatButton, &QPushButton::clicked, this, [&](){
		TrenchCoat tc = this->coats.front();
		std::string command = "start " + tc.getPhotographLink();
		std::system(command.c_str());
		});
}

UserWindow::UserWindow(ControllerUser& _controllerUser, QWidget* parent) : controllerUser{_controllerUser}, QWidget(parent)
{
	this->initMainLayout();
}

UserWindow::~UserWindow()
{
	//delete title
	delete this->titleLabel; this->titleLabel = nullptr;
	delete this->titleLayout; this->titleLayout = nullptr;

	delete this->sizeSButton; this->sizeSButton = nullptr;
	delete this->sizeMButton; this->sizeMButton = nullptr;
	delete this->sizeLButton; this->sizeLButton = nullptr;
	delete this->sizeXLButton; this->sizeXLButton = nullptr;
	delete this->sizeAllButton; this->sizeAllButton = nullptr;

	delete this->sizesGroup; this->sizesGroup = nullptr;

	delete this->sizeButtonsGroupLayout; this->sizeButtonsGroupLayout = nullptr;
	
	delete this->startPresentationCatalagoueButton; this->startPresentationCatalagoueButton = nullptr;
	delete this->openBasketFileButton; this->openBasketFileButton = nullptr;
	delete this->startOpenButtonsLayout; this->startOpenButtonsLayout = nullptr;

	
	delete this->addCoatToBasketButton; this->addCoatToBasketButton = nullptr;
	delete this->nextCoatButton; this->nextCoatButton = nullptr;
	delete this->displayCoatButton; this->displayCoatButton = nullptr;

	this->clearBasketTable();
	this->clearCurrentCoat();
	delete this->currentCoat; this->currentCoat = nullptr;
	delete this->basketTable; this->basketTable = nullptr;
	delete this->basketPriceLabel; this->basketPriceLabel = nullptr;

	delete this->navigationButtonsLayout; this->navigationButtonsLayout = nullptr;
	delete this->currentCoatLayout; this->currentCoatLayout = nullptr;
	delete this->basketTableLayout; this->basketTableLayout = nullptr;
	
	delete this->tablesLayout; this->tablesLayout = nullptr;

	
	delete this->mainLayout;
}