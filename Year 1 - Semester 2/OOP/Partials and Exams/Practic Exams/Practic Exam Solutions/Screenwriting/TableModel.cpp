#include "TableModel.h"

TableModel::TableModel(IdeasController& _c, QObject* parent) : QAbstractTableModel{parent}, c{_c}{
}

int TableModel::rowCount(const QModelIndex& parent) const{
    return this->c.getAll().size();
}

int TableModel::columnCount(const QModelIndex& parent) const{
    return 4;
}

QVariant TableModel::data(const QModelIndex& index, int role) const{
    int row = index.row();
    int col = index.column();
    Idea idea{this->c.getAll()[row]};
    if (role == Qt::DisplayRole){
        switch (col){
        case 0:
            return QString::fromStdString(idea.getDescription());
        case 1:
            return QString::fromStdString(idea.getStatus());
        case 2:
            return QString::fromStdString(idea.getCreator());
        case 3:
            return QString::number(idea.getAct());
        default:
            break;
        }
    }
    return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const{
    if (role == Qt::DisplayRole){
        if (orientation == Qt::Horizontal){
            switch (section){
            case 0:
                return QString{"Description"};
            case 1:
                return QString{"Status"};
            case 2:
                return QString{"Creator"};
            case 3:
                return QString{"Act"};
            default:
                break;
            }
        }
    }
    return QVariant();
}

void TableModel::addIdea(const Idea& i){
    int n = this->c.getAll().size();
    this->beginInsertRows(QModelIndex{}, n, n);
    this->c.addIdea(i);
    this->endInsertRows();
}

void TableModel::acceptIdea(const Idea& i, const std::string& newStatus){
    this->beginResetModel();
    this->c.updateIdeaStatus(i, newStatus);
    this->endResetModel();
}
