#include "pch.h"
#include "CppUnitTest.h"
#include "../SWE_App/ButtonFactory.h"
#include "../SWE_App/Calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

class WxTestApp : public wxApp
{
public:
	bool OnInit() override
	{
		return true;
	}
};

wxIMPLEMENT_APP_NO_MAIN(WxTestApp);

namespace SWEAppTests
{
	TEST_CLASS(ButtonFactoryTests)
	{
	private:

		void AssertButton(wxButton* button, int expectedId, const wxString& expectedLabel)
		{
			Assert::IsNotNull(button);

			Assert::AreEqual(expectedId, button->GetId());
			Assert::IsTrue(button->GetLabel() == expectedLabel);
		}

	public:

		TEST_CLASS_INITIALIZE(InitializeWxWidgets)
		{
			int argc = 0;
			wxChar** argv = nullptr;

			bool started = wxEntryStart(argc, argv);

			Assert::IsTrue(started);

			bool initialized = wxTheApp->CallOnInit();

			Assert::IsTrue(initialized);
		}

		TEST_CLASS_CLEANUP(CleanupWxWidgets)
		{
			if (wxTheApp != nullptr)
			{
				wxTheApp->OnExit();
			}

			wxEntryCleanup();
		}

		TEST_METHOD(CreateZeroButtonWorks)
		{
			wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "Test");

			wxButton* button = ButtonFactory::CreateZeroButton(frame);

			AssertButton(button, ID_BUTTON_0, "0");

			frame->Destroy();
		}

		TEST_METHOD(CreateOneButtonWorks)
		{
			wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "Test");

			wxButton* button = ButtonFactory::CreateOneButton(frame);

			AssertButton(button, ID_BUTTON_1, "1");

			frame->Destroy();
		}

		TEST_METHOD(CreateAddButtonWorks)
		{
			wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "Test");

			wxButton* button = ButtonFactory::CreateAddButton(frame);

			AssertButton(button, ID_BUTTON_ADD, "+");

			frame->Destroy();
		}

		TEST_METHOD(CreateSubtractButtonWorks)
		{
			wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "Test");

			wxButton* button = ButtonFactory::CreateSubtractButton(frame);

			AssertButton(button, ID_BUTTON_SUBTRACT, "-");

			frame->Destroy();
		}

		TEST_METHOD(CreateMultiplyButtonWorks)
		{
			wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "Test");

			wxButton* button = ButtonFactory::CreateMultiplyButton(frame);

			AssertButton(button, ID_BUTTON_MULTIPLY, "*");

			frame->Destroy();
		}

		TEST_METHOD(CreateDivideButtonWorks)
		{
			wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "Test");

			wxButton* button = ButtonFactory::CreateDivideButton(frame);

			AssertButton(button, ID_BUTTON_DIVIDE, "/");

			frame->Destroy();
		}

		TEST_METHOD(CreateModuloButtonWorks)
		{
			wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "Test");

			wxButton* button = ButtonFactory::CreateModuloButton(frame);

			AssertButton(button, ID_BUTTON_MODULO, "%");

			frame->Destroy();
		}

		TEST_METHOD(CreateSinButtonWorks)
		{
			wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "Test");

			wxButton* button = ButtonFactory::CreateSinButton(frame);

			AssertButton(button, ID_BUTTON_SIN, "SIN");

			frame->Destroy();
		}

		TEST_METHOD(CreateEqualsButtonWorks)
		{
			wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "Test");

			wxButton* button = ButtonFactory::CreateEqualsButton(frame);

			AssertButton(button, ID_BUTTON_EQUALS, "=");

			frame->Destroy();
		}

		TEST_METHOD(CreateClearButtonWorks)
		{
			wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "Test");

			wxButton* button = ButtonFactory::CreateClearButton(frame);

			AssertButton(button, ID_BUTTON_CLEAR, "C");

			frame->Destroy();
		}
	};
}