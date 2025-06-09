#ifndef TABEXTENDEDMODEL_H
#define TABEXTENDEDMODEL_H

#include <QAbstractItemModel>
#include <QString>
#include <QVector>


struct SkillStat {
    QString skill;
    int moda;
    int mediana;
    int mean;
};

class TabExtendedModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit TabExtendedModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section,
                        Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    // Basic functionality:
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void setDataList(const std::vector<SkillStat>& data);

private:
    std::unique_ptr<std::vector<SkillStat>> m_SkillStat;

};

#endif // TABEXTENDEDMODEL_H
