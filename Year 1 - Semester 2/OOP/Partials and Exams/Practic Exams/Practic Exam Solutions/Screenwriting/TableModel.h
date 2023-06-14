#pragma once

#include <QAbstractTableModel>
#include "IdeasController.h"

class TableModel : public QAbstractTableModel{
private:
    IdeasController& c;

public:
    TableModel(IdeasController& _c, QObject* parent = nullptr);
    int rowCount(const QModelIndex& parent = QModelIndex())const override;
    int columnCount(const QModelIndex& parent = QModelIndex())const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole)const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole)const override;

    void addIdea(const Idea& i);
    void acceptIdea(const Idea& i, const std::string& newStatus);

};