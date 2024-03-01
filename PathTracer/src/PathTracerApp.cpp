#include "Walnut/Application.h"
#include "Walnut/EntryPoint.h"

#include "Walnut/Image.h"
#include "Walnut/Random.h"

class ExampleLayer : public Walnut::Layer
{
public:
	virtual void OnAttach() override
	{
	}

	virtual void OnUIRender() override
	{
		// Setting planel
		ImGui::Begin("Setting");
		if(ImGui::Button("Button"))
		{
			render();
		}
		ImGui::End();

		// Viewport planel
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, {0.f, 0.f});
		ImGui::Begin("Viewport");
		m_viewport_width = ImGui::GetContentRegionAvail().x;
		m_viewport_height = ImGui::GetContentRegionAvail().y;
		if(m_image)
		{
			ImGui::Image(m_image->GetDescriptorSet(), {(float)m_image->GetWidth(), (float)m_image->GetHeight()});
		}	
		ImGui::End();
		ImGui::PopStyleVar();
	}

	void render()
	{
		// 如果m_image尚未创建，或者我们resize了viewport，那么都重新创建一个符合viewport大小的m_image
		if(!m_image || (m_image->GetWidth() != m_viewport_width || m_image->GetHeight() != m_viewport_height))
			m_image = std::make_shared<Walnut::Image>(m_viewport_width, m_viewport_height, Walnut::ImageFormat::RGBA);

		// 每次点击render，都需要重置一下image_data的内容
		delete[] m_image_data;
		m_image_data = new uint32_t[m_viewport_width * m_viewport_height];
		for(uint32_t i = 0; i < m_viewport_width * m_viewport_height; ++i)
		{
			// m_image_data每个元素为uint32_t，4B，每个B表示一个像素的一个通道的值，分别为ABGR
			m_image_data[i] = Walnut::Random::UInt();
			m_image_data[i] |= 0xff000000;
		}
		m_image->SetData(m_image_data);
	}
private:
	std::shared_ptr<Walnut::Image> m_image;
	uint32_t* m_image_data = nullptr;
	uint32_t m_viewport_width = 0,
		m_viewport_height = 0;
};

Walnut::Application* Walnut::CreateApplication(int argc, char** argv)
{
	Walnut::ApplicationSpecification spec;
	spec.Name = "Path Tracer";

	Walnut::Application* app = new Walnut::Application(spec);
	app->PushLayer<ExampleLayer>();
	app->SetMenubarCallback([app]()
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Exit"))
			{
				app->Close();
			}
			ImGui::EndMenu();
		}
	});
	return app;
}