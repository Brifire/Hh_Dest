#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <QObject>
#include <QSettings>
#include <QString>

class SettingsManager : public QObject
{
    Q_OBJECT

public:
    static SettingsManager& instance();

    void setValue(const QString &key, const QVariant &value);
    QVariant value(const QString &key, const QVariant &defaultValue = QVariant()) const;
    void remove(const QString &key);
    bool contains(const QString &key) const;
    void saveWindowGeometry(const QString &prefix, QWidget *window);
    void loadWindowGeometry(const QString &prefix, QWidget *window);
    static void clearSettings();

private:
    explicit SettingsManager(QObject *parent = nullptr);
    QSettings settings;
};

#endif // SETTINGSMANAGER_H
