#include "MyTable.h"
#include <QBrush>

MyTable::MyTable(const vector<Star> &arr) : arr(arr) {}

int MyTable::rowCount(const QModelIndex &parent) const {
    return arr.size();
}

int MyTable::columnCount(const QModelIndex &parent) const {
    return 5;
}

void MyTable::update(vector<Star>& new_arr) {
    arr = new_arr;
    auto top = createIndex(0,0);
    auto bottom = createIndex(rowCount(), columnCount());

    emit dataChanged(top, bottom);
    emit layoutChanged();
}

QVariant MyTable::data(const QModelIndex& index, int role) const{
    if(role == Qt::DisplayRole){
        auto& item = arr[index.row()];
        auto col = index.column();
        if(col == 0){
            return QString::fromStdString(item.getName());
        }
        if (col == 1){
            return QString::fromStdString(item.getConstellation());
        }
        if(col == 2){
            return QString::number(item.getRa());
        }
        if(col == 3){
            return QString::number(item.getDec());
        }
        if(col == 4){
            return QString::number(item.getDiameter());
        }
    }
    if(role == Qt::BackgroundRole){
        auto& item = arr[index.row()];
        if(item.getDiameter()>10){
            QBrush bg(Qt::lightGray);
            return bg;
        }
    }
    return QVariant{};
}

QVariant MyTable::headerData(int section, Qt::Orientation orientation, int role) const{
    if (role == Qt::DisplayRole){
        if (orientation == Qt::Horizontal){
            switch (section){
            case 0:
                return QString{"Name"};
            case 1:
                return QString{"Constellation"};
            case 2:
                return QString{"RA"};
            case 3:
                return QString{"Dec"};
            case 4:
                return QString{"Diameter"};
            default:
                break;
            }
        }
    }
    return QVariant();
}

bool MyTable::setData(const QModelIndex& index, const QVariant& value, int role)
{
    int row = index.row();
    int col = index.column();

    if (role != Qt::DisplayRole && role != Qt::EditRole){
        return false;
    }

    if (row < 0 || row >= rowCount()){
        return false;
    }

    if (col < 0 || col >= columnCount()){
        return false;
    }

    if (col == 1){
        return false;
    }

    Star& s = this->arr[row];

    bool changeOccured = false;
    switch (col){
    case 0:
    {
        std::string name{value.toString().toStdString()};
        s.setName(name);
        changeOccured = true;
        break;
    }
    case 2:
    {
        int ra = stod(value.toString().toStdString());
        s.setRa(ra);
        changeOccured = true;
        break;
    }
    case 3:
    {
        int dec = stod(value.toString().toStdString());
        s.setDec(dec);
        changeOccured = true;
        break;
    }
    case 4:
    {
        int diamater = stod(value.toString().toStdString());
        s.setDiameter(diamater);
        changeOccured = true;
        break;
    }
    default:
        break;
    }
    
    emit dataChanged(index, index);

    return changeOccured;
}

Qt::ItemFlags MyTable::flags(const QModelIndex& index) const
{
    int col = index.column();

    if (col != 1){
        return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
    }
    return Qt::ItemFlags();
}

