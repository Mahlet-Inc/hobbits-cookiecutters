#pragma once

#include "hobbits/abstractparametereditor.h"
#include "hobbits/parameterhelper.h"

namespace Ui
{
class {{cookiecutter.export_editor}};
}

class {{cookiecutter.export_editor}} : public AbstractParameterEditor
{
    Q_OBJECT

public:
    {{cookiecutter.export_editor}}(QSharedPointer<ParameterDelegate> delegate);
    ~{{cookiecutter.export_editor}}() override;

    QString title() override;

    bool setParameters(const Parameters &parameters) override;
    Parameters parameters() override;

private:
    void previewBitsImpl(QSharedPointer<BitContainerPreview> container,
                             QSharedPointer<PluginActionProgress> progress) override;
    void previewBitsUiImpl(QSharedPointer<BitContainerPreview> container) override;

    Ui::{{cookiecutter.export_editor}} *ui;
    QSharedPointer<ParameterHelper> m_paramHelper;
};

